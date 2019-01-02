#pragma once
#include "stdafx.h"

class AnimationCamera;

//负责摄像头位置的确定
class Camera
{
public:
	CVector pos;//摄像机位置
	CVector lookAt;//摄像机看向的物体的位置
	CVector up;//摄像机向上的方向
	CMatrix transMatrix;//变换矩阵 用于计算驾驶员视角
	CMatrix lastTransMatrix;//记录变换矩阵，主要是为了插值动画
	CMatrix innerTransMatrix;//内部变换矩阵（方便进行驾驶员视角的变换）

	static const int VIEW_POS_WORLD = 0;
	static const int VIEW_POS_CAR = 1;
	
	static const int VIEW_MODE_EULER = 0;//欧拉角模式
	static const int VIEW_MODE_ROAMING = 1;//自由漫游模式

	int viewMode;//欧拉角模式还是自由漫游模式
	int viewPos;//这个摄像头是世界摄像头还是驾驶员视角

	Camera();
	void work();
	void set(CVector _pos,//摄像机位置
		CVector _lookAt,//摄像机看向的物体的位置
		CVector _up);
	void set(float posx, float posy, float posz, float lookAtx, float lookAty, float lookAtz, float upx, float upy, float upz);
	bool loadTransMatrix(CMatrix& _transMatrix);
	void mulInnerTransMatrix(CMatrix& m);

	void modifySpeedMove(bool flag);//更改移动速度
	void modifySpeedRot(bool flag);//更改旋转速度

	//按下各个键
	void W();
	void S();
	void A();
	void D();
	void Q();//前进
	void E();//后退

	void I();
	void K();
	void J();
	void L();
	void U();
	void O();

	void Camera::moveCarCamera(float x, float y, float z);//限制车内摄像头的运动范围
	void Camera::moveGlobalCamera(float x, float y, float z);//移动世界摄像头

	void Camera::rotCarCamera(float degree, int x, int y, int z);//移动车内摄像头
	void Camera::rotGlobalCamera(float degree, int x, int y, int z);//移动世界摄像头

	//返回摄像头的位置，朝向信息
	void getCameraInfo(CVector& outPos, CVector& outLookAt, CVector& outUp);

	//设置动画摄像头
	void setAnimationCamera(AnimationCamera *a) { animation = a; };
	void delAnimationCamera() { animation = NULL; };

private:
	float speedMove ;//摄像机移动速度
	float speedRot;//摄像机旋转移动速度 角度 不是弧度

	float speedDeltaMove ;
	float speedDeltaRot ;

	AnimationCamera *animation;
};