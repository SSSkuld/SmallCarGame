#include "stdafx.h"
#include "CQuaternion.h"

void CQuaternion::Set(float _x, float _y, float _z, float _w)
{
	x = _x; y = _y; z = _z; w = _w;
}

CEuler CQuaternion::ToEuler()//四元数转换为欧拉角
{
	CEuler ret;
	double PI = acos(-1.0);
	ret.p = asin(2 * w*x - 2 * y*z);
	if (abs(cos(ret.p)) < eps) //cosp==0
		ret.h = atan2(2 * w*y - 2 * z*x, 1 - 2 * y*y - 2 * z*z);
	else ret.h = atan2(2 * z*x + 2 * w*y, 1 - 2 * x*x - 2 * y*y);

	if (abs(cos(ret.p)) < eps) //cosp==0
		ret.b = 0;
	else ret.b = atan2(2 * x*y + 2 * w*z, 1 - 2 * z*z - 2 * x*x);

	//转换为角度
	for (int i = 0; i < 3; i++) ret[i] = ret[i] / PI * 180;

	return ret;
}

CMatrix CQuaternion::ToMatrix()//四元数转换为矩阵
{
	CMatrix ret;
	for (int i = 0; i < 16; i++) ret[i] = 0;

	ret.m00 = 1 - 2 * y*y - 2 * z*z;
	ret.m10 = 2 * x*y + 2 * w*z;
	ret.m20 = 2 * x*z - 2 * w*y;

	ret.m01 = 2 * x*y - 2 * w*z;
	ret.m11 = 1 - 2 * x*x - 2 * z*z;
	ret.m21 = 2 * y*z + 2 * w*x;

	ret.m02 = 2 * x*z + 2 * w*y;
	ret.m12 = 2 * y*z - 2 * w*x;
	ret.m22 = 1 - 2 * x*x - 2 * y*y;

	ret.m33 = 1;
	return ret;
}

void CQuaternion::SetAngle(float angle, CVector axis) //四元数设置
{
	this->w = angle;
	this->x = axis.x; this->y = axis.y; this->z = axis.z;
}

CQuaternion& CQuaternion::operator=(const CQuaternion& p)//重载赋值
{
	this->w = p.w; this->x = p.x; this->y = p.y; this->z = p.z;
	return *this;
}

CQuaternion CQuaternion::operator+(const CQuaternion& p)//重载‘+’
{
	this->w += p.w; this->x += p.x; this->y += p.y; this->z += p.z;
	return *this;
}

CQuaternion CQuaternion::operator*(float data)//重载数乘
{
	this->w *= data; this->x *= data; this->y *= data; this->z *= data;
	return *this;
}

CQuaternion CQuaternion::operator*(const CQuaternion&p)//四元数乘法
{
	CQuaternion ret;
	ret.w = this->w*p.w - this->x*p.x - this->y*p.y - this->z*p.z;
	ret.x = this->w*p.x + this->x * p.w + this->z*p.y - this->y * p.z;
	ret.y = this->w*p.y + this->y * p.w + this->x*p.z - this->z * p.x;
	ret.z = this->w*p.z + this->z * p.w + this->y*p.x - this->x * p.y;
	return ret;
}

float CQuaternion::dotMul(const CQuaternion&p) //点乘
{
	float ret = w*p.w + x*p.x + y*p.y + z*p.z;
	return ret;
}

float CQuaternion::len()//求模
{
	return sqrt(this->x * this->x + this->y * this->y + this->z * this->z + this->w * this->w);
}

bool CQuaternion::Normalize()	//求标准化
{
	float len = this->len();
	for (int i = 0; i < 4; i++) (*this)[i] /= len;
	return true;
}

CQuaternion& CQuaternion::Inverse()//求逆四元数,会改变自身。
{
	(*this) = GetInverse();
	return (*this);
}

CQuaternion CQuaternion::GetInverse()//求逆四元数,不改变自身，生成新的四元数
{
	float len = this->len();
	CQuaternion conjugation = (*this);//共轭
	for (int i = 0; i < 3; i++)conjugation[i] = -conjugation[i];
	conjugation = conjugation * (1 / len / len);
	return conjugation;
}

CQuaternion CQuaternion::Div(const CQuaternion&b) //求差 当前为a,求c=a-b
{
	CQuaternion ret;
	ret = this->GetInverse() * b;
	return ret;
}

void CQuaternion::GetAngle(float& angle, CVector& axis)//求旋转轴和角度
{
	Normalize();
	angle = acos(w) * 2 * 180 / acos(-1.0);
	axis.x = x;
	axis.y = y;
	axis.z = z;
	axis.normalize();
}


CQuaternion CQuaternion::Slerp(const CQuaternion& Vend, float t) //插值。从当前四元数插值到Vend四元数,t是参数[0,1]
{
	float angle = 0.0f;
	CVector axis;
	CQuaternion tmp = *this;
	CQuaternion tmp1 = Vend;
	tmp.Normalize();
	tmp1.Normalize();
	CQuaternion ans = tmp.Div(tmp1);
	ans.Normalize();

	if (abs(ans.x) < eps && abs(ans.y) < eps && abs(ans.z) < eps) return *this;

	ans.GetAngle(angle, axis);
	float sinv = sin(t * angle / 360 * acos(-1.0)), cosv = cos(t * angle / 360 * acos(-1.0));
	ans.w = cosv;
	ans.x = axis.x * sinv;
	ans.y = axis.y * sinv;
	ans.z = axis.z * sinv;
	ans = tmp * ans;
	ans.Normalize();

	return ans;

}

void CQuaternion::Slerp(const CQuaternion& Vend, int n, float *t, CQuaternion *Result)//插值。一次插值出n个数据。插值参数保存在数组t中，结果返回到数组Result中。
{
	for (int i = 0; i < n; i++)
	{
		Result[i] = Slerp(Vend, t[i]);
	}
}