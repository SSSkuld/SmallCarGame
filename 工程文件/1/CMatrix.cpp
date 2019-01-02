#include "stdafx.h"
#include "CMatrix.h"


CMatrix& CMatrix::operator=(const CMatrix& p)    //矩阵赋值
{
	CMatrix tmp = p;

	for(int i =0;i<16;i++)
		(*this)[i] =tmp[i];

	return *this;
}

CMatrix CMatrix::operator*(float d)//矩阵数乘
{
	CMatrix ret = (*this);
	
	for(int i =0;i<16;i++)
		ret[i] = (*this)[i] * d;

	return ret ; 
}

CMatrix CMatrix::operator*(CMatrix& p)//矩阵相乘
{
	CMatrix ret;

	for(int c=0;c<4;c++)
	{
		for(int r =0;r<4;r++)
		{
			ret[4*c + r] = 0;
			for(int k =0;k<4;k++)
			{
				ret[4*c +r ] += (*this)[ 4*k+r ] * p[4*c + k];
			}
		}
	}
	return ret ;
}

CVector CMatrix::vecMul(CVector& p) //矩阵与向量相乘
{
	float v[4];
	float vret[4];
	for(int i=0;i<3;i++)
	{
		v[i]=p[i];
		vret[i]=0;
	}

	v[3]=vret[3]= 0;

	CVector ret;

	
	for(int r=0;r<4;r++)
	{
		for(int k=0;k<4;k++)
		{
			vret[r] += v[k] * (*this)[k*4 + r];  
		}
	}
	

	for(int i=0;i<3;i++)
		ret[i] = vret[i];

	return ret;
}


CVector CMatrix::posMul(CVector& p)
{
	float v[4];
	float vret[4];
	for(int i=0;i<3;i++)
	{
		v[i]=p[i];
		vret[i]=0;
	}

	v[3]=1;vret[3]=0;

	CVector ret;

	
	for(int r=0;r<4;r++)
	{
		for(int k=0;k<4;k++)
		{
			vret[r] += v[k] * (*this)[k*4 + r];  
		}
	}
	

	for(int i=0;i<3;i++)
		ret[i] = vret[i];

	return ret;
}


void CMatrix::SetRotate(float seta,CVector axis)	//设置为旋转矩阵
{
	for(int i=0;i<16;i++) (*this)[i] = 0;
	seta = seta * acos(-1.0) / 180;

	axis.normalize();
	(*this)[0] = axis[0] * axis[0] *(1-cos(seta)) + cos(seta);
	(*this)[1] = axis[0] * axis[1] * (1-cos(seta)) + axis[2]*sin(seta);
	(*this)[2] =  axis[0] *  axis[2] * (1-cos(seta)) - axis[1] * sin(seta); 
	(*this)[4] = axis[0] * axis[1] *(1-cos(seta)) - axis[2] * sin(seta);
	(*this)[5] = axis[1] * axis[1] * (1-cos(seta)) + cos(seta);
	(*this)[6] = axis[1] * axis[2] * (1-cos(seta)) + axis[0] * sin(seta);
	(*this)[8] = axis[0] * axis[2] * (1-cos(seta)) + axis[1] * sin(seta);
	(*this)[9] = axis[1] * axis[2] * (1-cos(seta)) - axis[0] * sin(seta);
	(*this)[10] = axis[2]*axis[2]* (1-cos(seta)) + cos(seta);
	(*this)[15] = 1;
}

void CMatrix::SetTrans(CVector trans)		//设置为平移矩阵
{
	for(int i=0;i<16;i++) (*this)[i] = 0;


	(*this)[12] = trans[0];
	(*this)[13] = trans[1];
	(*this)[14] = trans[2];

	(*this)[0] = 1;
	(*this)[5] = 1;
	(*this)[10] = 1;
	(*this)[15] = 1;
}

void CMatrix::SetScale(CVector p)		//设置为缩放矩阵
{
	for(int i=0;i<16;i++) (*this)[i] = 0;

	(*this)[0] = p[0];
	(*this)[5] = p[1];
	(*this)[10] = p[2];
	(*this)[15]=1;
}

float CMatrix::Inverse()//矩阵求逆,成功返回行列式的值，否则返回0
{
		//求行列式
	float arr[4][4];

	for(int r=0;r<4;r++)
		for(int c=0;c<4;c++)
			arr[r][c] = (*this)[ 4*c + r];

	float determinant =0;

	int tmp;
	float tmpArr[3][3];
	float algebraicRemainder[4][4];

	for(int r=0;r<4;r++)
	{
		for(int c=0;c<4;c++)
		{
			tmp = ((r+c)%2)?-1:1;

			//构建余子式
			for(int rr=0,i=0,j=0;rr<4;rr++)
			{
				for(int cc=0;cc<4;cc++)
				{
					if( rr==r || cc== c) continue;
							
					tmpArr[i][j] = arr[rr][cc];

					j++;
					if(j==3) i++,j=0;
				}
			}


			float t = calcDeterminant(tmpArr);
			algebraicRemainder[c][r] = t*tmp;
			if(r==0)determinant += arr[r][c] * tmp*t;
		}
	}

	float eps = 1e-6;

	if(abs(determinant)<eps) return 0;//行列式为0

	return determinant;

}

CMatrix CMatrix::GetInverse()//返回逆矩阵
{
		//求行列式
	float arr[4][4];

	for(int r=0;r<4;r++)
		for(int c=0;c<4;c++)
			arr[r][c] = (*this)[ 4*c + r];

	float determinant =0;

	int tmp;
	float tmpArr[3][3];
	float algebraicRemainder[4][4];

	for(int r=0;r<4;r++)
	{
		for(int c=0;c<4;c++)
		{
			tmp = ((r+c)%2)?-1:1;

			//构建余子式
			for(int rr=0,i=0,j=0;rr<4;rr++)
			{
				for(int cc=0;cc<4;cc++)
				{
					if( rr==r || cc== c) continue;
							
					tmpArr[i][j] = arr[rr][cc];

					j++;
					if(j==3) i++,j=0;
				}
			}


			float t = calcDeterminant(tmpArr);
			algebraicRemainder[c][r] = t*tmp;
			if(r==0)determinant += arr[r][c] * tmp*t;
		}
	}

	float eps = 1e-6;

	if(abs(determinant)<eps) return (*this);//行列式为0
	
	for(int r=0;r<4;r++)
		for(int c=0;c<4;c++)
			algebraicRemainder[r][c]/=determinant;

	CMatrix retMatrix;



	for(int r=0;r<4;r++)
		for(int c=0;c<4;c++)
		{
			retMatrix[ 4*c + r]=algebraicRemainder[r][c] + eps;
		}

	return retMatrix;
}


float CMatrix::calcDeterminant(float arr[3][3])
{
	float ans= 0;

	for(int i=0;i<3;i++)
		ans+=arr[0][i%3] * arr[1][(i+1) % 3] * arr[2][(i+2)%3];

	for(int i=0;i<3;i++)
		ans-=arr[0][i%3] * arr[1][(i-1+3) % 3] * arr[2][(i-2+3)%3];

	return ans;
}

CEuler CMatrix::ToEuler()//矩阵转换为欧拉角
{
	CEuler ret;
	float t = 180.0 / acos(-1.0);
	ret.p = asin(-m12) * t;
	ret.h = atan2(m02,m22) * t;
	ret.b = atan2(m10, m11) * t;
	ret.eulerNormal();
	return ret;
}


CQuaternion CMatrix::ToQuaternion()//矩阵转换为四元数
{
	CQuaternion ret;
	double w, x, y, z;
	
	w = sqrt(m00 + m11 + m22 + 1) / 2;
	x = sqrt(m00 - m11 - m33 + 1) / 2;
	y = sqrt(-m00 + m11 - m22 + 1) / 2;
	z = sqrt(-m00 - m11 + m22 + 1) / 2;

	double mx = std::max(std::max(w, x), std::max( y, z));
	if (mx == w)
	{
		x = (m21 - m12) / 4 / w;
		y = (m02 - m20) / 4 / w;
		z = (m10 - m01) / 4 / w;
	}
	else if (mx == x)
	{
		w = (m21 - m12) / 4 / x;
		y = (m10 + m01) / 4 / x;
		z = (m02 + m20) / 4 / x;
	}
	else if (mx == y)
	{
		w = (m02 - m20) / 4 / y;
		x = (m10 + m01) / 4 / y;
		z = (m21 + m12) / 4 / y;
	}
	else
	{
		w = (m10 - m01) / 4 / z;
		x = (m02 + m20) / 4 / z;
		y = (m21 + m12) / 4 / z;
	}
	ret.w = w;
	ret.x = x;
	ret.y = y;
	ret.z = z;
	return ret;
}

//转为单位矩阵
void CMatrix::loadIdentity()
{
	for(int i=0;i<16;i++) (*this)[i] = 0;
	m00 = m11=m22=m33=1;
}