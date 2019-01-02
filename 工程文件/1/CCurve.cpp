#include "stdafx.h"
#include "CCurve.h"


CCurve::CCurve(std::vector<CVector>& points)
	:points(points)
{
	for (int i = 1; i<points.size(); i++) {
		ls.push_back(Segment(points[i - 1], points[i]));
	}
	length = 0;
	len_list.push_back(0);
	for (int i = 0; i<ls.size(); i++) {
		length += ls[i].length;
		len_list.push_back(length);
	}
}



//计算折线交点，没有则返回false
bool CCurve::calcu_intersection(CCurve& other, std::vector<CVector>& ret
	, Segment::Mode mode)
{
	ret.clear();
	CVector tmp;
	bool flag;
	for (int i = 0; i<this->ls.size(); i++) {
		for (int j = 0; j<other.ls.size(); j++) {
			flag = ls[i].calcu_intersection(other.ls[j], tmp, mode);
			if (flag) {
				ret.push_back(tmp);
			}
		}
	}
	if (ret.size() == 0)
		return false;
	return true;
}
//点到折线距离
float CCurve::calcu_distance(CVector point, CVector& ret
	, Segment::Mode mode, int* ret_index)
{
	int _index = 0;
	float min_dist = ls[0].calcu_distance(point, ret, mode);
	float tmp;
	CVector tmp_v;
	for (int i = 1; i<this->ls.size(); i++) {
		tmp = ls[i].calcu_distance(point, tmp_v, mode);
		if (tmp<min_dist) {
			min_dist = tmp;
			ret = tmp_v;
			_index = i;
		}
	}
	if (ret_index != nullptr)*ret_index = _index;
	return min_dist;
}
//计算在折线中从end[0]向end[1]移动move_dist到达的点
CVector CCurve::calcu_pos(float move_dist, int* const index)
{
	if (move_dist<0)return points[0];
	float rest = move_dist;
	int i;
	for (i = 0; i<ls.size(); i++) {
		if (rest>ls[i].length) {
			rest -= ls[i].length;
		}
		else {
			break;
		}
	}
	if (i == ls.size()) {
		if (index != nullptr)*index = points.size() - 1;
		return points[points.size() - 1];
	}
	else {
		if (index != nullptr)*index = i;
		return ls[i].calcu_pos(rest);
	}

}


//计算从起始索引点向终点沿折线移动move_dist到达的点
CVector CCurve::calcu_pos_from_idx(float move_dist, int from_index
	, int* const ret_index, float* const dist_to_ret_idx)
{
	float total_dist = this->len_list[from_index] + move_dist;
	CVector ans = calcu_pos(total_dist, ret_index);
	if (ret_index != nullptr) {
		if (dist_to_ret_idx != nullptr) {
			*dist_to_ret_idx = (ans - points[*ret_index]).len();
		}
	}
	return ans;
}

//看点是否在折线中
bool CCurve::check_in_curve(CVector& point, Segment::Mode mode)
{
	bool ans = false;
	for (int i = 0; i<ls.size(); i++) {
		ans = ls[i].check_in_line_segment(point, mode);
		if (true == ans)return true;
	}
	return false;
}

//看点是否在折线内部
bool CCurve::check_inside_curve(CVector& point, Segment::Mode mode) {
	bool ans = false;
	double angle_sum = 0;
	double angle;
	CVector v1, v2;
	int size = points.size();
	for (int i = 0; i<size; i++) {
		v1 = points[i] - point;
		v2 = points[(i + 1) % size] - point;
		if (mode>0) {
			v1[mode] = 0;
			v2[mode] = 0;
		}
		angle = calc_angle(v1, v2);
		angle_sum += angle;
	}

	if (fabs(angle_sum - 360)<0.01) {//0.01度的忍耐极限
		return true;
	}
	else {
		//检查是否在端点上,如果是，则也算在内部
		for (int i = 0; i<points.size(); i++) {
			if (point == points[i])return true;
		}
		return false;
	}
}


Segment::Mode CCurve::get_mode(int type) {
	if (type == 0) {
		return Segment::Mode::_IGNORE_X;
	}
	else if (type == 1) {
		return Segment::Mode::_IGNORE_Y;
	}
	else if (type == 2) {
		return Segment::Mode::_IGNORE_Z;
	}
	else {
		return Segment::Mode::_3D;
	}
}


float CCurve::calc_angle(CVector v1, CVector v2)
{
	v1.normalize();
	v2.normalize();
	//因为是浮点数，所以处理临界会很麻烦
	if (check_equal(v1, v2))return 0;
	if (check_equal(v1, -v2))return 180;
	CVector rotate_axis = v1.crossMul(v2);
	float tmp = v1.dotMul(v2);

	tmp = (tmp > 1) ? 1 : ((tmp < -1) ? -1 : tmp);

	float theta = acos(tmp) * 180 / acos(-1.0);
	return theta;
}


bool CCurve::check_equal(CVector v1, CVector v2)
{
	for (int i = 0; i<3; i++) {
		if (  abs( v1[i] - v2[i]) > (1e-6) )
			return false;
	}
	return true;
}