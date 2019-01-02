#pragma once


class Segment
{
public:
	enum Mode { _3D = -1, _IGNORE_X = 0, _IGNORE_Y = 1, _IGNORE_Z = 2 };//����ģʽ
	Segment(CVector end0, CVector end1);

	Segment(Segment& other) {
		end[0] = other.end[0], end[1] = other.end[1];
		length = other.length;
	}
	Segment operator=(Segment& other) {
		end[0] = other.end[0], end[1] = other.end[1];
		length = other.length;
	}
	//�����߶ν��㣬û���򷵻�false
	bool calcu_intersection(Segment& other, CVector& ret, Mode mode = _3D);
	//�㵽�߶ξ���,ret��ʾ�����
	float calcu_distance(CVector point, CVector& ret, Mode mode = _3D);
	//�������߶��д�end[0]��end[1]�ƶ�move_dist����ĵ�
	CVector calcu_pos(float move_dist);
	//�����Ƿ����߶���
	bool check_in_line_segment(CVector& point, Mode mode = _3D);

	//�߶�����ν���
	bool calcu_intersec_rect(CVector ver, CVector vec_length, CVector vec_width
		, CVector& ret, bool segment_mode = true, bool half_line_mode = true);

	CVector end[2];
	float length;

private:
	float eps;

};

