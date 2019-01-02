#include "stdafx.h"
#include "Camera.h"


void Camera::work()
{
	//innerTransMatrix
	CVector _pos = pos;
	CVector _lookAt = lookAt;
	CVector _up = up;

	_pos = (transMatrix*innerTransMatrix).posMul(_pos);
	_lookAt = (transMatrix*innerTransMatrix).posMul(_lookAt);
	_up = (transMatrix*innerTransMatrix).vecMul(_up);

	glLoadIdentity();

	gluLookAt(_pos.x, _pos.y, _pos.z ,
		_lookAt.x, _lookAt.y, _lookAt.z,
		_up.x, _up.y, _up.z);
}


void Camera::set(CVector _pos,//�����λ��
	CVector _lookAt,//��������������λ��
	CVector _up)
{
	pos = _pos; lookAt = _lookAt; up = _up;
}

void Camera::set(float posx, float posy, float posz, float lookAtx, float lookAty, float lookAtz, float upx, float upy, float upz)
{
	pos.x = posx; pos.y = posy; pos.z = posz;
	lookAt.x = lookAtx; lookAt.y = lookAty; lookAt.z = lookAtz;
	up.x = upx; up.y = upy; up.z = upz;
}

//�����Ƿ�ᴥ������
bool Camera::loadTransMatrix(CMatrix& _transMatrix)
{
	for (int i = 0; i < 16; i++)
	{
		lastTransMatrix[i] = transMatrix[i];
		transMatrix[i] = _transMatrix[i];
	}

	if (animation == NULL) return false;

	CVector lastPos = pos;
	CVector lastLookAt = lookAt;
	CVector lastUp = up;

	lastPos = (lastTransMatrix*innerTransMatrix).posMul(lastPos);
	lastLookAt = (lastTransMatrix*innerTransMatrix).posMul(lastLookAt);
	lastUp = (lastTransMatrix*innerTransMatrix).vecMul(lastUp);

	CVector curPos = pos;
	CVector curLookAt = lookAt;
	CVector curUp = up;

	curPos = (transMatrix*innerTransMatrix).posMul(curPos);
	curLookAt = (transMatrix*innerTransMatrix).posMul(curLookAt);
	curUp = (transMatrix*innerTransMatrix).vecMul(curUp);

	return true;
}

void Camera::mulInnerTransMatrix(CMatrix& m)
{
	innerTransMatrix = innerTransMatrix * m;
}

Camera::Camera()
{
	transMatrix.loadIdentity();
	innerTransMatrix.loadIdentity();

	speedMove = 0.2f;//������ƶ��ٶ�
	speedRot = 0.6f;//�������ת�ƶ��ٶ� �Ƕ� ���ǻ���

	speedDeltaMove = 0.2f;
	speedDeltaRot = 0.2f;
}

void Camera::modifySpeedMove(bool flag)//�����ƶ��ٶ�
{
	if (flag) speedMove += speedDeltaMove;
	else speedMove -= speedDeltaMove;

	speedMove = max(0.2f, speedMove);
	speedMove = min(5.0f, speedMove);
}


void Camera::modifySpeedRot(bool flag)//������ת�ٶ�
{
	if (flag) speedRot += speedDeltaRot;
	else speedRot -= speedDeltaRot;

	speedRot = max(0.2f, speedRot);
	speedRot = min(4.0f, speedRot);
}


void Camera::W()
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(0, speedMove, 0);
	else moveCarCamera(0, speedMove, 0);
}

void Camera::S()
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(0,- speedMove, 0);
	else moveCarCamera(0, -speedMove, 0);
}

void Camera::A()
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(-speedMove, 0, 0);
	else moveCarCamera(speedMove, 0, 0);
}

void Camera::D()
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(speedMove, 0, 0);
	else moveCarCamera(-speedMove, 0, 0);
}
void Camera::Q()//ǰ��
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(0, 0, speedMove);
	else moveCarCamera(0, 0, speedMove);
}
void Camera::E()//����
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(0, 0, -speedMove);
	else moveCarCamera(0, 0, -speedMove);
}

void Camera::I()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(speedRot, 1, 0, 0);
	else rotCarCamera(-speedRot, 1, 0, 0);
}
void Camera::K()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(-speedRot, 1, 0, 0);
	else rotCarCamera(speedRot, 1, 0, 0);
}
void Camera::J()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(speedRot,0,1,0);
	else rotCarCamera(speedRot, 0, 1, 0);
}
void Camera::L()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(-speedRot, 0, 1, 0);
	else rotCarCamera(-speedRot, 0, 1, 0);
}
void Camera::U()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(-speedRot, 0, 0, -1);
	else rotCarCamera(speedRot, 0, 0, -1);
}

void Camera::O()
{
	if (viewPos == VIEW_POS_WORLD)
		rotGlobalCamera(speedRot, 0, 0, -1);
	else rotCarCamera(-speedRot, 0, 0, -1);
}


void Camera::moveCarCamera(float x, float y, float z)
{
	glPushMatrix();
	glLoadMatrixf(innerTransMatrix);
	glTranslatef(x, y, z);
	CMatrix tmpM;
	glGetFloatv(GL_MODELVIEW_MATRIX, tmpM);
	CVector tmpV;
	//�жϳ���ԭ�������ͷ����λ�ƺ��Ƿ���ڳ���
	tmpV.x = tmpV.y = tmpV.z = 0;
	tmpV = tmpM.posMul(tmpV);

	//�������ͷ�ڳ��ھ͸���innerTransMatrix
	if (tmpV.x*tmpV.x + tmpV.y*tmpV.y + tmpV.z*tmpV.z <= 0.23) innerTransMatrix = tmpM;
	glPopMatrix();
}

void Camera::moveGlobalCamera(float x, float y, float z)//�ƶ���������ͷ
{
	CVector vLookAt = lookAt - pos;
	CVector move;
	if(x) move = vLookAt.crossMul(up) * x;
	else if (y)
	{
		up.normalize();
		move = up*y;
	}
	else
	{
		move = vLookAt * z;
	}

	pos = pos + move;
	lookAt = lookAt + move;
}

void Camera::rotGlobalCamera(float degree,int x,int y,int z)//��ת��������ͷ
{
	glPushMatrix();
	glLoadIdentity();
	if (viewMode == VIEW_MODE_EULER)
	{	
		CVector vLookAt = lookAt - pos;
		CMatrix m;
		//�������ӽ���ˮƽ��ת
		glRotatef(degree, x, y, z);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);

		//��������ͷ�µ�λ�ã�������
		vLookAt = m.vecMul(vLookAt);
		lookAt = pos + vLookAt;
		up = m.vecMul(up);
	}
	else
	{

		CVector vLookAt;
		vLookAt = lookAt - pos;

		//�������ӽ���ˮƽ��ת
		CVector rotAxis;//��ת��
		if (x) rotAxis = vLookAt.crossMul(up);
		else if (y)rotAxis = up;
		else rotAxis = vLookAt;

		CMatrix m;
		glLoadIdentity();
		glRotatef(degree, rotAxis. x, rotAxis.y, rotAxis.z);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
		//�����µ�����ͷ��λ�úͳ���
		vLookAt = m.vecMul(vLookAt);
		lookAt = pos + vLookAt;
		up = m.vecMul(up);
	}
	glPopMatrix();
}

void Camera::rotCarCamera(float degree, int x, int y, int z)
{
	glPushMatrix();
	//glLoadIdentity();
	glLoadMatrixf(innerTransMatrix);
	glRotatef(degree, x, y, z);
	glGetFloatv(GL_MODELVIEW_MATRIX, innerTransMatrix);
	glPopMatrix();
}


void Camera::getCameraInfo(CVector& outPos, CVector& outLookAt, CVector& outUp)
{
	CVector _pos = pos;
	CVector _lookAt = lookAt;
	CVector _up = up;

	_pos = (transMatrix*innerTransMatrix).posMul(_pos);
	_lookAt = (transMatrix*innerTransMatrix).posMul(_lookAt);
	_up = (transMatrix*innerTransMatrix).vecMul(_up);

	outPos = _pos;
	outLookAt = _lookAt;
	outUp = _up;
}