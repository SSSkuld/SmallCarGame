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


void Camera::set(CVector _pos,//摄像机位置
	CVector _lookAt,//摄像机看的物体的位置
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

//返回是否会触发动画
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

	speedMove = 0.2f;//摄像机移动速度
	speedRot = 0.6f;//摄像机旋转移动速度 角度 不是弧度

	speedDeltaMove = 0.2f;
	speedDeltaRot = 0.2f;
}

void Camera::modifySpeedMove(bool flag)//更改移动速度
{
	if (flag) speedMove += speedDeltaMove;
	else speedMove -= speedDeltaMove;

	speedMove = max(0.2f, speedMove);
	speedMove = min(5.0f, speedMove);
}


void Camera::modifySpeedRot(bool flag)//更改旋转速度
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
void Camera::Q()//前进
{
	if (viewPos == VIEW_POS_WORLD)
		moveGlobalCamera(0, 0, speedMove);
	else moveCarCamera(0, 0, speedMove);
}
void Camera::E()//后退
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
	//判断车内原点的摄像头经过位移后是否会在车外
	tmpV.x = tmpV.y = tmpV.z = 0;
	tmpV = tmpM.posMul(tmpV);

	//如果摄像头在车内就更新innerTransMatrix
	if (tmpV.x*tmpV.x + tmpV.y*tmpV.y + tmpV.z*tmpV.z <= 0.23) innerTransMatrix = tmpM;
	glPopMatrix();
}

void Camera::moveGlobalCamera(float x, float y, float z)//移动世界摄像头
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

void Camera::rotGlobalCamera(float degree,int x,int y,int z)//旋转世界摄像头
{
	glPushMatrix();
	glLoadIdentity();
	if (viewMode == VIEW_MODE_EULER)
	{	
		CVector vLookAt = lookAt - pos;
		CMatrix m;
		//在世界视角上水平旋转
		glRotatef(degree, x, y, z);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);

		//计算摄像头新的位置，朝向方向
		vLookAt = m.vecMul(vLookAt);
		lookAt = pos + vLookAt;
		up = m.vecMul(up);
	}
	else
	{

		CVector vLookAt;
		vLookAt = lookAt - pos;

		//在现有视角上水平旋转
		CVector rotAxis;//旋转轴
		if (x) rotAxis = vLookAt.crossMul(up);
		else if (y)rotAxis = up;
		else rotAxis = vLookAt;

		CMatrix m;
		glLoadIdentity();
		glRotatef(degree, rotAxis. x, rotAxis.y, rotAxis.z);
		glGetFloatv(GL_MODELVIEW_MATRIX, m);
		//计算新的摄像头的位置和朝向
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