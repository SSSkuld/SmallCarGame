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

CMatrix& operator=(const CMatrix& p);//����ֵ
CMatrix operator*(float d);//��������
CMatrix operator*(CMatrix& p);//�������
CVector vecMul(CVector& p); //�������������
CVector posMul(CVector& p);//����������
void SetRotate(float seta,CVector axis);	//����Ϊ��ת����
void SetTrans(CVector trans);		//����Ϊƽ�ƾ���
void SetScale(CVector p);		//����Ϊ���ž���
float Inverse();//��������,�ɹ���������ʽ��ֵ�����򷵻�0
CMatrix GetInverse();//���������

CEuler ToEuler();//����ת��Ϊŷ����
CQuaternion ToQuaternion();//����ת��Ϊ��Ԫ��

void loadIdentity();

private:
	float calcDeterminant(float arr[3][3]);
	//double CMatrix::max(double x1, double x2, double x3, double x4);

};