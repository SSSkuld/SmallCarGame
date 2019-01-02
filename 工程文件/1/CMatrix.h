//#include "opengl\OpenGL.h"
//#include "opengl\glVector.h"
//#include "opengl\glVector3.h"
#pragma once
#include "CVector.h"
#include "CEuler.h"
#include "CQuaternion.h"
#include <math.h>
#include <algorithm>

class CMatrix
{
public:
float m00,m10,m20,m30;
float m01,m11,m21,m31;
float m02,m12,m22,m32;
float m03,m13,m23,m33;

//void Set(float *val);
operator float*(){return &m00;}

CMatrix& operator=(const CMatrix& p);//矩阵赋值
CMatrix operator*(float d);//矩阵数乘
CMatrix operator*(CMatrix& p);//矩阵相乘
CVector vecMul(CVector& p); //矩阵与向量相乘
CVector posMul(CVector& p);//矩阵与点相乘
void SetRotate(float seta,CVector axis);	//设置为旋转矩阵
void SetTrans(CVector trans);		//设置为平移矩阵
void SetScale(CVector p);		//设置为缩放矩阵
float Inverse();//矩阵求逆,成功返回行列式的值，否则返回0
CMatrix GetInverse();//返回逆矩阵

CEuler ToEuler();//矩阵转换为欧拉角
CQuaternion ToQuaternion();//矩阵转换为四元数

void loadIdentity();

private:
	float calcDeterminant(float arr[3][3]);
	//double CMatrix::max(double x1, double x2, double x3, double x4);

};