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

	//欧拉角转换为向量
	CVector ToVector(CVector *updir = 0);//如果传入updir指针不为0，则输出向量同时输出上方向量到updir中。
	
	//欧拉角转换为矩阵
	CMatrix ToMatrix();

	//欧拉角转换为四元数
	CQuaternion ToQuaternion();

	//欧拉角规范化//h,r角度在-180~180，p角度在-90~90。万向锁时,h代替所有r的度数。
	void eulerNormal();

};
