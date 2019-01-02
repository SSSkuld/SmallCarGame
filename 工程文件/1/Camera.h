#pragma once
#include "stdafx.h"

class AnimationCamera;

//��������ͷλ�õ�ȷ��
class Camera
{
public:
	CVector pos;//�����λ��
	CVector lookAt;//���������������λ��
	CVector up;//��������ϵķ���
	CMatrix transMatrix;//�任���� ���ڼ����ʻԱ�ӽ�
	CMatrix lastTransMatrix;//��¼�任������Ҫ��Ϊ�˲�ֵ����
	CMatrix innerTransMatrix;//�ڲ��任���󣨷�����м�ʻԱ�ӽǵı任��

	static const int VIEW_POS_WORLD = 0;
	static const int VIEW_POS_CAR = 1;
	
	static const int VIEW_MODE_EULER = 0;//ŷ����ģʽ
	static const int VIEW_MODE_ROAMING = 1;//��������ģʽ

	int viewMode;//ŷ����ģʽ������������ģʽ
	int viewPos;//�������ͷ����������ͷ���Ǽ�ʻԱ�ӽ�

	Camera();
	void work();
	void set(CVector _pos,//�����λ��
		CVector _lookAt,//���������������λ��
		CVector _up);
	void set(float posx, float posy, float posz, float lookAtx, float lookAty, float lookAtz, float upx, float upy, float upz);
	bool loadTransMatrix(CMatrix& _transMatrix);
	void mulInnerTransMatrix(CMatrix& m);

	void modifySpeedMove(bool flag);//�����ƶ��ٶ�
	void modifySpeedRot(bool flag);//������ת�ٶ�

	//���¸�����
	void W();
	void S();
	void A();
	void D();
	void Q();//ǰ��
	void E();//����

	void I();
	void K();
	void J();
	void L();
	void U();
	void O();

	void Camera::moveCarCamera(float x, float y, float z);//���Ƴ�������ͷ���˶���Χ
	void Camera::moveGlobalCamera(float x, float y, float z);//�ƶ���������ͷ

	void Camera::rotCarCamera(float degree, int x, int y, int z);//�ƶ���������ͷ
	void Camera::rotGlobalCamera(float degree, int x, int y, int z);//�ƶ���������ͷ

	//��������ͷ��λ�ã�������Ϣ
	void getCameraInfo(CVector& outPos, CVector& outLookAt, CVector& outUp);

	//���ö�������ͷ
	void setAnimationCamera(AnimationCamera *a) { animation = a; };
	void delAnimationCamera() { animation = NULL; };

private:
	float speedMove ;//������ƶ��ٶ�
	float speedRot;//�������ת�ƶ��ٶ� �Ƕ� ���ǻ���

	float speedDeltaMove ;
	float speedDeltaRot ;

	AnimationCamera *animation;
};