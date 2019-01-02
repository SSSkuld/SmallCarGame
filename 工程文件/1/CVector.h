#pragma once
#include <string.h>
#include "CEuler.h"

class CEuler;
class CMatrix;
class CQuaternion;

class CVector
{

public:
	float x, y, z;
	void set(float _x, float _y, float _z);
	CVector()
	{eps = 1e-6;}

	float& operator[](int i);

	CVector operator+(CVector& v);
	CVector operator-(CVector& v);
	CVector operator-();
	void operator=(CVector& v);
	bool operator==(CVector& v);
	bool operator!=(CVector& v);
	CVector operator*(float k);//数乘
	
	CVector crossMul(CVector& v);
	float dotMul(CVector& v);

	void normalize();//向量标准化
	float len();//求模

	CVector project(CVector v);//投影

///////////////////////////
	CEuler ToEuler();//向量转换为欧拉角

private:
	float eps;
};


