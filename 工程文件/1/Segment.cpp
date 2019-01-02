#include "stdafx.h"
#include "Segment.h"


Segment::Segment(CVector end0, CVector end1)
{
	end[0] = end0, end[1] = end1;
	length = (end1 - end0).len();
	eps = 1e-6;
}


//计算线段交点，没有则返回false
bool Segment::calcu_intersection(Segment& other, CVector& ret, Mode mode)
{
	CVector p0(end[0]), p_end0(end[1]);
	CVector p1(other.end[0]), p_end1(other.end[1]);
	switch (mode) {
	case _3D:
		break;
	case _IGNORE_X:
		p0.x = p_end0.x = p1.x = p_end1.x = 0;
		break;
	case _IGNORE_Y:
		p0.y = p_end0.y = p1.y = p_end1.y = 0;
		break;
	case _IGNORE_Z:
		p0.z = p_end0.z = p1.z = p_end1.z = 0;
		break;
	}

	if ((p1 - p0).len()<eps) {
		ret = p0;
		return true;
	}
	CVector d0(p_end0 - p0);
	d0.normalize();
	CVector d1(p_end1 - p1);
	d1.normalize();
	CVector _cross = d0.crossMul(d1);
	double _cross_len = _cross.len();
	if (_cross_len<eps) {
		if ((p_end0 - p0).len()<eps && (p_end1 - p1).len()<eps) {
			ret = p0;
			if (mode >= 0)ret[mode] = end[0][mode];
			return true;
		}
		return false;
	}

	else {
		double tmp = ((p1 - p0).crossMul(d1)).dotMul(_cross);
		double t = (double)tmp / (_cross_len*_cross_len);
		double rate = t / this->length;
		if (tmp<eps) {
			return false;
		}
		else {
			CVector v = end[0] + (end[1] - end[0])*rate;
			ret = p0 + d0*t;
			if (mode >= 0)ret[mode] = v[mode];
			return true;
		}
	}

}
//点到线段距离
float Segment::calcu_distance(CVector point, CVector& ret, Mode mode)
{
	CVector p0(end[0]), p_end0(end[1]);
	CVector _point(point);
	switch (mode) {
	case _3D:
		break;
	case _IGNORE_X:
		p0.x = p_end0.x = _point.x = 0;
		break;
	case _IGNORE_Y:
		p0.y = p_end0.y = _point.y = 0;
		break;
	case _IGNORE_Z:
		p0.z = p_end0.z = _point.z = 0;
		break;
	}
	CVector nearest;
	CVector d = p_end0 - p0;
	d.normalize();
	nearest = p0 + d*(_point - p0).dotMul(d);
	float rate = (nearest - p0).len() / this->length;
	if (rate<0)nearest = p0;
	else if (rate>1)nearest = p_end0;
	ret = nearest;
	float ans = (nearest - _point).len();
	return ans;
}
//计算在线段中从end[0]向end[1]移动move_dist到达的点
CVector Segment::calcu_pos(float move_dist)
{
	CVector d = (end[1] - end[0]);
	d.normalize();
	return end[0] + d*move_dist;
}

//看点是否在线段中
bool Segment::check_in_line_segment(CVector& point, Mode mode)
{

	CVector p0(end[0]), p_end0(end[1]);
	CVector _point(point);
	switch (mode) {
	case _3D:
		break;
	case _IGNORE_X:
		p0.x = p_end0.x = _point.x = 0;
		break;
	case _IGNORE_Y:
		p0.y = p_end0.y = _point.y = 0;
		break;
	case _IGNORE_Z:
		p0.z = p_end0.z = _point.z = 0;
		break;
	}
	CVector vec = _point - p0, d = p_end0 - p0;
	if (vec.len()>this->length)return false;
	if (vec.crossMul(d).len() >= eps)return false;
	if (vec.dotMul(d)<0)return false;
	return true;
}

//线段与矩形交点
bool Segment::calcu_intersec_rect(CVector ver, CVector vec_length, CVector vec_width
	, CVector& ret, bool segment_mode, bool half_line_mode)
{
	CVector n = vec_length.crossMul(vec_width);
	n.normalize();

	float d_len_1 = (end[1] - end[0]).dotMul(n);
	float d_len_2 = (ver - end[0]).dotMul(n);
	float t = d_len_2 / d_len_1;

	if (segment_mode) {
		if ((t>1 || t<0)) {
			return false;
		}
	}
	else {
		if (t<0 && half_line_mode) {
			return false;
		}
	}
	ret = end[0] + (end[1] - end[0])*t;
	CVector v1 = ver + vec_length;
	CVector v2 = ver + vec_width;
	if ((ret - ver).dotMul(vec_length)*(ret - v1).dotMul(vec_length)>0) {
		return false;
	}
	if ((ret - ver).dotMul(vec_width)*(ret - v2).dotMul(vec_width)>0) {
		return false;
	}
	return true;
}
