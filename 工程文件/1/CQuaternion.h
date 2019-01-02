#pragma once
#include "CMatrix.h"
#include "CEuler.h"
#include "CVector.h"

class CEuler;
class CMatrix;
class CVector;

class CQuaternion
{
public:
	CQuaternion()
	{
		eps=1e-6;
	}

	float x, y, z, w;
	void Set(float x, float y, float z, float w);
	operator float*() { return &x; }

	CEuler ToEuler();//��Ԫ��ת��Ϊŷ����
	CMatrix ToMatrix();//��Ԫ��ת��Ϊ����

	void SetAngle(float angle, CVector axis); //��Ԫ������
	CQuaternion& operator=(const CQuaternion& p); //���ظ�ֵ
	CQuaternion operator+(const CQuaternion& p); //���ء�+��
	CQuaternion operator*(float data);//��������
	CQuaternion operator*(const CQuaternion&p);//��Ԫ���˷�
	float dotMul(const CQuaternion&p); //���
	float len(); //��ģ
	bool Normalize();	//���׼��
	CQuaternion& Inverse();//������Ԫ��,��ı�����
	CQuaternion GetInverse();//������Ԫ��,���ı����������µ���Ԫ��
	CQuaternion Div(const CQuaternion&b); //��� ��ǰΪa,��c=a-b
	void GetAngle(float& angle, CVector& axis); //����ת��ͽǶ�
	CQuaternion Slerp(const CQuaternion& Vend, float t); //��ֵ���ӵ�ǰ��Ԫ����ֵ��Vend��Ԫ��,t�ǲ���[0,1]
	void Slerp(const CQuaternion& Vend, int n, float *t, CQuaternion *Result);//��ֵ��һ�β�ֵ��n�����ݡ���ֵ��������������t�У�������ص�����Result�С�

	//CQuaternion Power(float t);
private:
	float eps ;
};
