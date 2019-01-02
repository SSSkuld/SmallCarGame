#pragma once
#include "CMatrix.h"
#include "CVector.h"
#include "CQuaternion.h"


class CMatrix;
class CVector;
class CQuaternion;

class CEuler
{
private:
	float eps ;
public:
	CEuler()
	{eps = 1e-6;}

	float h, p, b;
	void Set(float _h, float _p, float _b);
	operator float*() { return &h; }

	//ŷ����ת��Ϊ����
	CVector ToVector(CVector *updir = 0);//�������updirָ�벻Ϊ0�����������ͬʱ����Ϸ�������updir�С�
	
	//ŷ����ת��Ϊ����
	CMatrix ToMatrix();

	//ŷ����ת��Ϊ��Ԫ��
	CQuaternion ToQuaternion();

	//ŷ���ǹ淶��//h,r�Ƕ���-180~180��p�Ƕ���-90~90��������ʱ,h��������r�Ķ�����
	void eulerNormal();

};
