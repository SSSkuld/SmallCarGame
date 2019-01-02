#pragma once
#include "Segment.h"

class CCurve
{
public:
	CCurve(std::vector<CVector>& points);

	//�������߽��㣬û���򷵻�false
	bool calcu_intersection(CCurve& other, std::vector<CVector>& ret
		, Segment::Mode mode = Segment::_3D);
	//�㵽���߾���,ret��ʾ�����
	float calcu_distance(CVector point, CVector& ret
		, Segment::Mode mode = Segment::_3D, int* ret_index = nullptr);
	//�������ʼ�����յ��������ƶ�move_dist����ĵ�
	CVector calcu_pos(float move_dist, int* const index = nullptr);
	//�������ʼ���������յ��������ƶ�move_dist����ĵ�
	CVector calcu_pos_from_idx(float move_dist, int from_index = 0
		, int* const ret_index = nullptr, float* const dist_to_ret_idx = nullptr);
	//�����Ƿ���������
	bool check_in_curve(CVector& point, Segment::Mode mode = Segment::_3D);
	//�����Ƿ��������ڲ����ҿ���û��⵽�������üнǷ��򵥴���ֻ��ƽ��ͼ����Ч���������������
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