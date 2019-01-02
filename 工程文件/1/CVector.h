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
	CVector operator*(float k);//����
	
	CVector crossMul(CVector& v);
	float dotMul(CVector& v);

	void normalize();//������׼��
	float len();//��ģ

	CVector project(CVector v);//ͶӰ

///////////////////////////
	CEuler ToEuler();//����ת��Ϊŷ����

private:
	float eps;
};


