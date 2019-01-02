#pragma once
#include "Segment.h"

class CCurve
{
public:
	CCurve(std::vector<CVector>& points);

	//计算折线交点，没有则返回false
	bool calcu_intersection(CCurve& other, std::vector<CVector>& ret
		, Segment::Mode mode = Segment::_3D);
	//点到折线距离,ret表示最近点
	float calcu_distance(CVector point, CVector& ret
		, Segment::Mode mode = Segment::_3D, int* ret_index = nullptr);
	//计算从起始点向终点沿折线移动move_dist到达的点
	CVector calcu_pos(float move_dist, int* const index = nullptr);
	//计算从起始索引点向终点沿折线移动move_dist到达的点
	CVector calcu_pos_from_idx(float move_dist, int from_index = 0
		, int* const ret_index = nullptr, float* const dist_to_ret_idx = nullptr);
	//看点是否在折线中
	bool check_in_curve(CVector& point, Segment::Mode mode = Segment::_3D);
	//看点是否在折线内部（我可能没理解到，现在用夹角法简单处理，只对平面图形有效，会有例外情况）
	bool check_inside_curve(CVector& point, Segment::Mode mode = Segment::_3D);

	static Segment::Mode get_mode(int type);

	float CCurve::calc_angle(CVector v1, CVector v2);
	bool CCurve::check_equal(CVector v1, CVector v2);

public:
	std::vector<CVector> points;
	std::vector<Segment> ls;
	std::vector<double> len_list;
	double length;


};