#pragma once


class Segment
{
public:
	enum Mode { _3D = -1, _IGNORE_X = 0, _IGNORE_Y = 1, _IGNORE_Z = 2 };//计算模式
	Segment(CVector end0, CVector end1);

	Segment(Segment& other) {
		end[0] = other.end[0], end[1] = other.end[1];
		length = other.length;
	}
	Segment operator=(Segment& other) {
		end[0] = other.end[0], end[1] = other.end[1];
		length = other.length;
	}
	//计算线段交点，没有则返回false
	bool calcu_intersection(Segment& other, CVector& ret, Mode mode = _3D);
	//点到线段距离,ret表示最近点
	float calcu_distance(CVector point, CVector& ret, Mode mode = _3D);
	//计算在线段中从end[0]向end[1]移动move_dist到达的点
	CVector calcu_pos(float move_dist);
	//看点是否在线段中
	bool check_in_line_segment(CVector& point, Mode mode = _3D);

	//线段与矩形交点
	bool calcu_intersec_rect(CVector ver, CVector vec_length, CVector vec_width
		, CVector& ret, bool segment_mode = true, bool half_line_mode = true);

	CVector end[2];
	float length;

private:
	float eps;

};

