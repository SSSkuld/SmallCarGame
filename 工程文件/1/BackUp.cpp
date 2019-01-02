#include "StdAfx.h"

void drawNameTest()
{
	glPushMatrix();

	float interval =1;
	//ºÎ ×óÊú 
	//(-10,-19) (3,-19)
	float radius =1;
	
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);		
	//glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);		


	for(float i=-10;i<=2;i+=interval) //0-12
	{
		glPushMatrix();
		glTranslatef(-20,i,0);
		glRotatef(90,0,0,1);
		//drawCircle(radius);
		glPopMatrix();
	}

	{//Ä©±Ê 13
		glPushMatrix();
		glTranslatef(-20,3,0);
		glRotatef(45,0,0,1);
		//drawCircle(radius);
		glPopMatrix();
	}

	//ºÎ ×óÉÏ½Ç
	for(float i=0,x=-23,y=2;i<=9;i+=interval) //14 - 23
	{
		glPushMatrix();
		glTranslatef(x+i,y+i,0);
		glRotatef(45,0,0,1);
		//drawCircle(radius);
		glPopMatrix();
	}
	
	//ºÎ ÉÏºá
	
	for(float i=-17;i<=-2;i+=interval) //23 - 38
	{
		glPushMatrix();
		glTranslatef(i,8,0);
		//glRotatef(,0,0,1);
		//drawCircle(radius);
		glPopMatrix();
	}
	//»ØÐ´
	for(float i=-2;i>=-4;i--) // 39-45
	{
		glPushMatrix();
		glTranslatef(i,8,0);
		if(i==-4)
			glRotatef(45,0,0,1);
		//drawCircle(radius);
		glPopMatrix();
	}
	//ÓÒÊú
	for(float i=8;i>=-10;i--) //46  - 64
	{
		glPushMatrix();
		glTranslatef(-4,i,0);

		if(i==-10)
			glRotatef(135,0,0,1);
		else 
			glRotatef(-90,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//×óÉÏ¹ý¶È
	for(float i=1,x=-4,y=-10;i<=5;i+=interval) // 65 - 70
	{
		glPushMatrix();
		glTranslatef(x-i,y+i,0);

		if(i==5)
			glRotatef(90,0,0,1);
		else 
			glRotatef(135,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¿Ú ÓÒ±ßÊú
	for(float i=1,x=-9,y=-5;i<=7;i+=interval) // 71 - 78
	{
		glPushMatrix();
		glTranslatef(x,y+i,0);

		if(i==7)
			glRotatef(135,0,0,1);
		else 
			glRotatef(90,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¿Ú ÉÏºá
	for(float i=1,x=-9,y=2;i<=5;i+=interval) // 79 - 84
	{
		glPushMatrix();
		glTranslatef(x-i,y,0);

		if(i==5)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¿Ú×óÊú
	for(float i=1,x=-14,y=2;i<=7;i+=interval)
	{
		glPushMatrix();
		glTranslatef(x,y-i,0);

		if(i==7)
			glRotatef(135,0,0,1);
		else 
			glRotatef(90,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¿ÚÏÂºá
	for(float i=1,x=-14,y=-5;i<=5;i+=interval)
	{
		glPushMatrix();
		glTranslatef(x+i,y,0);

		if(i==5)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}

	//yue Æ²
	for(float i = 0,x=11,y=10; i<=8;i+=1)
	{
		glPushMatrix();
		glTranslatef(x-i,y-i,0);

		if(i==8)
			glRotatef(45,0,0,1);
		else 
			glRotatef(45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//1ºá
	for(float i = 0,x=10,y=8; i<=5;i+=1)
	{
		glPushMatrix();
		glTranslatef(x+i,y,0);

		if(i==5)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//2ºá
	for(float i = 0,x=6,y=3; i<=9;i+=1)
	{
		glPushMatrix();
		glTranslatef(x+i,y,0);

		if(i==9)
			glRotatef(0,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//»Øºá
	for(float i = 0,x=15,y=3; i<=4;i+=1)
	{
		glPushMatrix();
		glTranslatef(x-i,y,0);

		if(i==4)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}

	//shu
	for(float i = 1,x=11,y=3; i<=13;i+=1)
	{
		glPushMatrix();
		glTranslatef(x,y-i,0);

		if(i==13)
			glRotatef(45,0,0,1);
		else 
			glRotatef(90,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¹³
	for(float i = 1,x=11,y=-10; i<=6;i+=1)
	{
		glPushMatrix();
		glTranslatef(x+i,y+i,0);

		if(i==6)
			glRotatef(0,0,0,1);
		else 
			glRotatef(45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}

	glPopMatrix();
//3ºá
	for (float i = 1,x=17,y=-4; i<=11;i+=1)
	{
		glPushMatrix();
		glTranslatef(x-i,y,0);

		if(i==11)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//ÓÒºá
	for (float i = 1,x=32,y=2; i<=13;i+=1)
	{
		glPushMatrix();
		glTranslatef(x-i,y,0);

		if(i==13)
			glRotatef(45,0,0,1);
		else 
			glRotatef(0,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//ÓÒÊú
	for (float i = 1,x=19,y=2; i<=12;i+=1)
	{
		glPushMatrix();
		glTranslatef(x,y-i,0);

		if(i==13)
			glRotatef(45,0,0,1);
		else 
			glRotatef(90,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//¹³
	for (float i = 1,x=19,y=-10; i<=5;i+=1)
	{
		glPushMatrix();
		glTranslatef(x+i,y+i,0);

		if(i==5)
			glRotatef(90,0,0,1);
		else 
			glRotatef(45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//Ð±¹³
	for (float i = 1,x=24,y=13; i<=8;i+=0.5)
	{
		glPushMatrix();
		glTranslatef(x+i,y-3*i,0);

		if(i==8)
			glRotatef(90,0,0,1);
		else 
			glRotatef(-45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}

	//¹³
	for (float i = 1,x=32,y=-11; i<=7;i+=1)
	{
		glPushMatrix();
		glTranslatef(x,y+i,0);

		if(i==7)
			glRotatef(45,0,0,1);
		else 
			glRotatef(-45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//ÓÒÏÂ½Ç Æ²
	for (float i = 1,x=32,y=-4; i<=6;i+=1)
	{
		glPushMatrix();
		glTranslatef(x-i,y-i,0);

		if(i==4)
			glRotatef(45,0,0,1);
		else 
			glRotatef(45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}
	//ÓÒÉÏ½Ç µã
	for (float i = 1,x=29,y=11; i<=5;i+=1)
	{
		glPushMatrix();
		glTranslatef(x+i,y-i,0);

		if(i==4)
			glRotatef(-45,0,0,1);
		else 
			glRotatef(-45,0,0,1);

		//drawCircle(radius);
		glPopMatrix();
	}

}

void drawCircle(float radius)
{
	/*
	glBegin(GL_LINE_STRIP);	
	//glBegin(GL_TRIANGLE_STRIP);		
	
	for(int j=0;j<CIRCLENUM;j++)
		glVertex3f(0,radius*posCircleX[j],radius*posCircleY[j]);

	glEnd();
	*/
}

void printNameInTxt()
{

	float interval = 1;
	//ºÎ ×óÊú 
	//(-10,-19) (3,-19)
	float radius = 1;

	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);		
	//glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);		

	FILE* cir = fopen("cir.txt", "w");
	FILE* car = fopen("car.txt", "w");
	//cir
	//x,y,z,ratAng,nx,ny,nz
	//start x,y,z end x,y,z  x,y,z rotAngle nx,ny,nz  //calc the dis


	for (float i = -10; i <= 3; i += interval) //0-12
	{
		fprintf(cir, "%.2f %.2f %.2f", -20.0, i, 0);
			 
		if (i == 3)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0,1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 90, 0, 0, 1);
		}

		if(i==-10)
			fprintf(car, "%.2f %.2f %.2f", -20.0, i, 0);
		else if(i==3)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", -20.0, i, 0, 90, 0, 0, 1);		 	 
	}

	//ºÎ ×óÉÏ½Ç
	for (float i = 0, x = -23, y = 2; i <= 9; i += interval) //14 - 23
	{
		fprintf(cir, "%.2f %.2f %.2f", x+i, y+i, 0);

		if (i == 9)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x + i, y + i, 0);
		else if (i == 9)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x + i, y + i, 0, 45, 0, 0, 1);

		//glTranslatef(x + i, y + i, 0);
		//glRotatef(45, 0, 0, 1);
				 
	}

	//ºÎ ÉÏºá

	for (float i = -17; i <= -2; i += interval) //23 - 38
	{
		fprintf(cir, "%.2f %.2f %.2f", i, 8.0, 0);

		if (i == -2)
		{
			fprintf(cir, " %d %d %d %d 1\n", 0, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == -17)
			fprintf(car, "%.2f %.2f %.2f", i, 8.0, 0);
		else if (i == -2)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", i, 8.0 , 0, 0, 0, 0, 1);

		//glTranslatef(i, 8, 0);
		//glRotatef(,0,0,1);
		  
	}
	//»ØÐ´
	for (float i = -2; i >= -4; i--) // 39-45
	{
		fprintf(cir, "%.2f %.2f %.2f",  i, 8.0, 0);

		if (i == -4)
		{
			fprintf(cir, " %d %d %d %d 1\n", 0, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == -2)
			fprintf(car, "%.2f %.2f %.2f", i,  8.0 , 0);
		else if (i == -4)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", i, 8.0 , 0, 0, 0, 0, 1);
	 
	}
	//ÓÒÊú
	for (float i = 8; i >= -10; i--) //46  - 64
	{
		fprintf(cir, "%.2f %.2f %.2f", -4.0, i, 0);

		if (i == -10)
		{
			fprintf(cir, " %d %d %d %d 1\n", 135, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", -90, 0, 0, 1);
		}

		if (i == 8)
			fprintf(car, "%.2f %.2f %.2f", -4.0,  i, 0);
		else if (i == -10)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", -4.0,  i, 0, -90, 0, 0, 1);

		//glTranslatef(-4, i, 0);
		/*
		if (i == -10)
			glRotatef(135, 0, 0, 1);
		else
			glRotatef(-90, 0, 0, 1);
	 */
	}
	//×óÉÏ¹ý¶È
	for (float i = 0, x = -4, y = -10; i <= 5; i += interval) // 65 - 70
	{
		fprintf(cir, "%.2f %.2f %.2f", x - i,y+ i, 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", 90, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 135, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x - i, y+i, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x - i, y+i, 0, 135, 0, 0, 1);

		/*glTranslatef(x - i, y + i, 0);

		if (i == 5)
			glRotatef(90, 0, 0, 1);
		else
			glRotatef(135, 0, 0, 1);	 */
		 
	}
	//¿Ú ÓÒ±ßÊú
	for (float i = 0, x = -9, y = -5; i <= 7; i += interval) // 71 - 78
	{
		fprintf(cir, "%.2f %.2f %.2f", x, y + i, 0);

		if (i == 7)
		{
			fprintf(cir, " %d %d %d %d 1\n", 135, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 90, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x , y + i, 0);
		else if (i == 7)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x, y + i, 0, 90, 0, 0, 1);

		/*
		glTranslatef(x, y + i, 0);

		if (i == 7)
			glRotatef(135, 0, 0, 1);
		else
			glRotatef(90, 0, 0, 1);
		*/		 
	}
	//¿Ú ÉÏºá
	for (float i = 0, x = -9, y = 2; i <= 5; i += interval) // 79 - 84
	{
		fprintf(cir, "%.2f %.2f %.2f", x-i, y, 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x-i, y, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x-i, y, 0, 0, 0, 0, 1);

		/*
		glTranslatef(x - i, y, 0);

		if (i == 5)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);
	 */
	}
	//¿Ú×óÊú
	for (float i = 0, x = -14, y = 2; i <= 7; i += interval)
	{
		fprintf(cir, "%.2f %.2f %.2f", x, y - i, 0);

		if (i == 7)
		{
			fprintf(cir, " %d %d %d %d 1\n", 135, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 90, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x, y - i, 0);
		else if (i == 7)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x, y - i, 0, 90, 0, 0, 1);

		/*
		glTranslatef(x, y - i, 0);

		if (i == 7)
			glRotatef(135, 0, 0, 1);
		else
			glRotatef(90, 0, 0, 1);

		 */
		 
	}
	//¿ÚÏÂºá
	for (float i = 0, x = -14, y = -5; i <= 5; i += interval)
	{
		fprintf(cir, "%.2f %.2f %.2f", x+i, y , 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x+i, y, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x+i, y , 0, 0, 0, 0, 1);
		/*
		glTranslatef(x + i, y, 0);

		if (i == 5)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);
			*/ 		 
	}

	//yue Æ²
	for (float i = 0, x = 11, y = 10; i <= 8; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x - i, y - i, 0);

		if (i == 8)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x - i, y - i, 0);
		else if (i == 8)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x - i, y - i, 0, 45, 0, 0, 1);

		/*
		glTranslatef(x - i, y - i, 0);

		if (i == 8)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(45, 0, 0, 1);
			*/
		 
		 
	}
	//1ºá
	for (float i = 0, x = 10, y = 8; i <= 5; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x + i, y, 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x + i, y, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x + i, y, 0, 0, 0, 0, 1);

		/*
		glTranslatef(x + i, y, 0);

		if (i == 5)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);

		 */
		 
	}
	//2ºá
	
	for (float i = 0, x = 6, y = 3; i <= 9; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x + i, y, 0);

		if (i == 9)
		{
			fprintf(cir, " %d %d %d %d 1\n", 0, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x + i, y, 0);
		else if (i == 9)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x + i, y, 0, 0, 0, 0, 1);
		/*
		glTranslatef(x + i, y, 0);

		if (i == 9)
			glRotatef(0, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);*/
	 
	}
	//»Øºá
	for (float i = 0, x = 15, y = 3; i <= 4; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x - i, y, 0);

		if (i == 4)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x + i, y, 0);
		else if (i == 4)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x + i, y, 0, 0, 0, 0, 1);
		/*glTranslatef(x - i, y, 0);

		if (i == 4)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);
			*/
		 
		 
	}

	//shu
	for (float i = 0, x = 11, y = 3; i <= 13; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x , y-i, 0);

		if (i == 13)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 90, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x , y-i, 0);
		else if (i == 13)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x, y-i, 0, 90, 0, 0, 1);
		/*
		glTranslatef(x, y - i, 0);

		if (i == 13)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(90, 0, 0, 1);
		*/
		 
		 
	}
	//¹³
	for (float i = 0, x = 11, y = -10; i <= 6; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x + i, y+i, 0);

		if (i == 6)
		{
			fprintf(cir, " %d %d %d %d 1\n", 0, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n",45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x + i, y+i, 0);
		else if (i == 6)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x + i, y+i, 0, 45, 0, 0, 1);
		/*
		glTranslatef(x + i, y + i, 0);

		if (i == 6)
			glRotatef(0, 0, 0, 1);
		else
			glRotatef(45, 0, 0, 1);
		*/
		 
		 
	}

	 
	//3ºá
	for (float i = 0, x = 17, y = -4; i <= 11; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x - i, y, 0);

		if (i == 11)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x -i, y , 0);
		else if (i == 11)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x - i, y , 0, 0, 0, 0, 1);
		/*glTranslatef(x - i, y, 0);

		if (i == 11)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);
			*/
		 
		 
	}
	//ÓÒºá
	for (float i = 0, x = 32, y = 2; i <= 13; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x - i, y , 0);

		if (i == 13)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 0, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x - i, y , 0);
		else if (i == 13)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x - i, y , 0, 0, 0, 0, 1);
		/*glTranslatef(x - i, y, 0);

		if (i == 13)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(0, 0, 0, 1);
		*/
		 
	}
	//ÓÒÊú
	for (float i = 0, x = 19, y = 2; i <= 12; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x , y - i, 0);

		if (i == 12)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 90, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x , y - i, 0);
		else if (i == 12)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x , y - i, 0, 90, 0, 0, 1);
		/*glTranslatef(x, y - i, 0);

		if (i == 13)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(90, 0, 0, 1);
			*/	 
	}
	//¹³
	for (float i = 0, x = 19, y = -10; i <= 5; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x+i, y + i, 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", 90, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x+i, y + i, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x+i, y + i, 0, 45, 0, 0, 1);
		/*glTranslatef(x + i, y + i, 0);

		if (i == 5)
			glRotatef(90, 0, 0, 1);
		else
			glRotatef(45, 0, 0, 1);
			*/
		 
		 
	}
	//Ð±¹³
	for (float i = 0, x = 24, y = 13; i <= 8; i += 0.5)
	{
		fprintf(cir, "%.2f %.2f %.2f", x+i, y -3* i, 0);

		if (i == 8)
		{
			fprintf(cir, " %d %d %d %d 1\n", 90, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", -45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x+i, y -3* i, 0);
		else if (i == 8)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x+i, y -3* i, 0, -45, 0, 0, 1);
		/*glTranslatef(x + i, y - 3 * i, 0);

		if (i == 8)
			glRotatef(90, 0, 0, 1);
		else
			glRotatef(-45, 0, 0, 1);

		 */
		 
	}

	//¹³
	for (float i = 0, x = 32, y = -11; i <= 7; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x, y + i, 0);

		if (i == 7)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", -45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x, y + i, 0);
		else if (i == 7)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x, y + i, 0, -45, 0, 0, 1);
		/*glTranslatef(x, y + i, 0);

		if (i == 7)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(-45, 0, 0, 1);
		*/
		 		 
	}
	//ÓÒÏÂ½Ç Æ²
	for (float i = 0, x = 32, y = -4; i <= 6; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x-i, y - i, 0);

		if (i == 6)
		{
			fprintf(cir, " %d %d %d %d 1\n", 45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", 45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x-i, y - i, 0);
		else if (i == 6)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x-i, y - i, 0, 45, 0, 0, 1);

		/*glTranslatef(x - i, y - i, 0);

		if (i == 4)
			glRotatef(45, 0, 0, 1);
		else
			glRotatef(45, 0, 0, 1);
			*/	 
	}
	//ÓÒÉÏ½Ç µã
	for (float i = 0, x = 29, y = 11; i <= 5; i += 1)
	{
		fprintf(cir, "%.2f %.2f %.2f", x+i, y - i, 0);

		if (i == 5)
		{
			fprintf(cir, " %d %d %d %d 1\n", -45, 0, 0, 1);
		}
		else
		{
			fprintf(cir, " %d %d %d %d 0\n", -45, 0, 0, 1);
		}

		if (i == 0)
			fprintf(car, "%.2f %.2f %.2f", x+i, y - i, 0);
		else if (i == 5)
			fprintf(car, " %.2f %.2f %.2f %d %d %d %d\n", x, y - i, 0, -45, 0, 0, 1);
		/*glTranslatef(x + i, y - i, 0);

		if (i == 4)
			glRotatef(-45, 0, 0, 1);
		else
			glRotatef(-45, 0, 0, 1);
			*/
		 
		 
	}
	
}

