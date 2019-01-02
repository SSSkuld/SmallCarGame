
#include "stdafx.h"
#include "CVector.h"
#include <math.h>

void CVector::set(float _x, float _y, float _z)
{
	x = _x; y = _y; z = _z;
}

CVector CVector::operator+(CVector& v)
{
	CVector  ans;
	for (int i = 0; i < 3; i++)
		ans[i] = (*this)[i] + v[i];
	
	return ans;
}

CVector CVector::operator-(CVector& v)
{
	CVector  ans;
	for (int i = 0; i < 3; i++)
		ans[i] = (*this)[i] - v[i];

	return ans;
}

CVector CVector::operator-()
{
	CVector v;
	v.set(-x, -y, -z);
	return v;
}

void CVector::operator=(CVector& v)
{
	for (int i = 0; i < 3; i++)
		(*this)[i]  = v[i];
}

bool CVector::operator==(CVector& v)
{
	bool ans = true;
	for (int i = 0; i < 3; i++)
		ans &= (*this)[i] == v[i];
	return ans;
}

bool CVector::operator!=(CVector& v)
{
	return !((*this) == v);
}

CVector CVector::operator*(float k)
{
	CVector ans;
	for (int i = 0; i < 3; i++)
		ans[i]= (*this)[i] *k;
	return ans;
}

float CVector::dotMul(CVector& v)
{
	float ans = 0;
	for (int i = 0; i < 3; i++)
		ans += (*this)[i] * v[i];
	return ans;
}

CVector CVector::crossMul(CVector& v)
{
	CVector ans;
	ans.x = y*v.z - z*v.y;
	ans.y = v.x*z - x*v.z;
	ans.z = x*v.y - v.x*y;
	return ans;
}

float CVector::len()//求模
{
	float l = 0;
	l = sqrt(x*x + y*y + z*z);
	return l;
}

void CVector::normalize()//向量标准化
{
	float l = len();
	x /= l;
	y /= l;
	z /= l;
}

float& CVector::operator[](int i)
{
	i %= 3;
	switch (i)
	{
	case 0: return x;
	case 1:return y;
	case 2: return z;
	}
	return x;
}

CVector CVector::project(CVector v)//投影
{
	CVector ans;
	v.normalize();
	ans =v*(*this).dotMul( v);
	return ans;
}

CEuler CVector::ToEuler()
{
	CEuler ret; 

	if (abs(x) < eps && abs(z) < eps && abs(y)>eps ) // (0,1,0)
	{
		if (y > 0)
		{
			ret.h = 0; ret.p = 90; ret.b = 0;
		}
		else
		{
			ret.h = 0; ret.p = -90; ret.b = 0;
		}
		return ret;
	}

	double a = 1;
	double b = x*x + z*z;
	double c = (z+1)*(z+1) + x*x ;

	double angle = (a+b-c)/(2*sqrt(a) * sqrt(b));

	angle = min(1.0-(1e-6),angle);
	angle = max(-1.0,angle);

	angle = acos(angle);
	angle = angle / acos(-1.0) * 180;
	
	if (x > 0) ret.h = -angle;
	else ret.h = angle;
	ret.b = 0;

	angle = sqrt(b) / this->len();
	angle = min(1.0,angle);
	angle = max(-1.0,angle);
	angle = acos(angle);
	angle = angle / acos(-1.0) * 180;
	
	if (y >= 0) ret.p = angle;
	else ret.p = -angle;

	return ret;
}
