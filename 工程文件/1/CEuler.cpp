#include "stdafx.h"
#include "CEuler.h"

void CEuler::Set(float _h, float _p, float _b)
{
	h = _h; p = _p; b = _b;
}

////欧拉角规范化//h,b角度在-180~180，p角度在-90~90。万向锁时,h代替所有b的度数。
void CEuler::eulerNormal()
{
	//h
	int tmp = h / 360;
	h -= tmp * 360;

	if (h < -180) h += 360;
	if (h > 180) h -= 360;

	tmp = b / 360;
	b -= tmp * 360;

	if (b < -180) b += 360;
	if (b > 180) b -= 360;

	tmp = p / 180;
	p -= tmp * 180;
	if (p < -90) p += 180;
	if (p > 90) p -= 180;

	//万向锁
	if (abs(p - 90) < eps)
		b = 0;

}

CMatrix CEuler::ToMatrix()
{
	CMatrix ret;
	CMatrix y,x,z;
	CVector tmp;
	tmp.x = 0; tmp.y = 1; tmp.z = 0;
	y.SetRotate(h, tmp);
	tmp.x = 1; tmp.y = 0; tmp.z = 0;
	x.SetRotate(p, tmp);
	tmp.x = 0; tmp.y = 0; tmp.z = 1;
	z.SetRotate(b, tmp);
	ret = y*x*z;
	return ret;
}

//欧拉角转换为向量
//如果传入updir指针不为0，则输出向量同时输出上方向量到updir中。
//物体绕自身y轴（即上向量up）旋转的角度。
CVector CEuler::ToVector(CVector *updir )
{
	CVector ret;
	ret.set(0, 0, -1);
	CMatrix rot = this->ToMatrix();
	ret = rot.vecMul(ret);

	if (updir)
	{
		CVector up; up.set(0, 1, 0);
		up = rot.vecMul(up);
		*updir = up;
	}

	return ret;
}

CQuaternion CEuler::ToQuaternion()
{
	double PI = acos(-1.0);
	double h = this->h * PI / 180; h /= 2;
	double p = this->p * PI / 180; p /= 2;
	double b = this->b *PI / 180; b /= 2;

	CQuaternion ret; 
	ret.w = cos(h)*cos(p)*cos(b) + sin(h)*sin(p)*sin(b);
	ret.x = cos(h)*sin(p)*cos(b) + sin(h)*cos(p)*sin(b);
	ret.y = sin(h)*cos(p)*cos(b) - cos(h)*sin(p)*sin(b);
	ret.z = cos(h)*cos(p)*sin(b) - sin(h)*sin(p)*cos(b);
	return ret;
}