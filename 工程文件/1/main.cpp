// 1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Camera.h"
#include "Car.h"


const int MAXN = 1e3;
wchar_t str[MAXN];

bool keyDown[300];//��¼��Щ��������

////
void myTimerFunc(int val);
void ReshapeFunc(int w, int h);
////

//��Ⱦ����
void DisplayFunc()
{

	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glPushMatrix();	
	

	glPopMatrix();

	glutSwapBuffers();
}

void KeyboardFunc(unsigned char key, int x, int y)
{
	keyDown[key] = 1;
}

void KeyboardUpFunc(unsigned char key, int x, int y)
{
	keyDown[key] = false;
}

void KeyboardSpecialFunc(int key, int x, int y)
{
	keyDown[key+100] = 1;
}

void KeyboardSpecialUpFunc(int key, int x, int y)
{
	keyDown[key + 100] = false;
}

int _tmain(int argc, _TCHAR* argv[])
{


	glutInit(&argc,(char**) &argv);
	glutInitWindowPosition(100,100);
	glutInitWindowSize(1200,500);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE| GLUT_DEPTH);
	glutCreateWindow("���ڱ���");

	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	
	glutDisplayFunc(&DisplayFunc);
	
	glutKeyboardFunc(KeyboardFunc);
	glutKeyboardUpFunc(KeyboardUpFunc);
	glutSpecialFunc(KeyboardSpecialFunc);
	glutSpecialUpFunc(KeyboardSpecialUpFunc);

	glutTimerFunc(10,myTimerFunc,1);
	glutReshapeFunc(&ReshapeFunc);


	glutMainLoop();//����ѭ��
	
	system("pause");

	return 0;
}


///////////////////////////////////////////////

void ReshapeFunc(int w, int h)
{
	GLfloat nRange = 100.0f;
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, GLfloat(w) / h, 1, 1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void checkKeyBoard()
{
	

}

void myTimerFunc(int val)
{
	checkKeyBoard();
	DisplayFunc();
	glutTimerFunc(20, myTimerFunc, 1);
}

