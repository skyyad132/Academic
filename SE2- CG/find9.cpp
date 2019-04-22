#include <iostream>
using namespace std;
#include <math.h>
#include <GL/glut.h>
#define SIN 0.866
#define COS 0.5
 
void Koch(int X1,int Y1,int X2,int Y2,int n);
void Menu(int choice);
 
void Init()
{
    glClearColor(1.0,1.0,1.0,0);
    glColor3f(0.0,0.0,0.0);
    glLineWidth(3);
    gluOrtho2D(0 , 640 , 0 , 480);
}
 
void Display()
{
  	glClear(GL_COLOR_BUFFER_BIT );
	glFlush();
}
 
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);
	
	cout<<"\n\t\t\t**KOCH CURVE**\n";
	
	glutCreateWindow("KOCH CURVE");
	Init();
	glutDisplayFunc(Display);
	glutCreateMenu(Menu);
		glutAddMenuEntry("Line",1);
		glutAddMenuEntry("Triangle",2);
		glutAddMenuEntry("Exit",0);
	glutAttachMenu(GLUT_RIGHT_BUTTON);		
	glutMainLoop();
}
 
void Line()
{
	double x1,y1,x2,y2;
	
	cout<<"\n\tLINE : \n";
	cout<<"\n\tEnter Co-ords (X1,Y1) >> ";
	cin>>x1>>y1;
	cout<<"\n\tEnter Co-ords (X2,Y2) >> ";
	cin>>x2>>y2;
	
	glBegin(GL_LINE_STRIP);
		glColor3f(0.5,0.5,0.5);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
		glColor3f(0,0,0);		
	glEnd();
	glFlush();
	
	Koch(x2,y2,x1,y1,3);
}
 
void Triangle()
{
	double x1,y1,x2,y2,x3,y3;
	
	cout<<"\n\n\tTRIANGLE : \n";
	cout<<"\n\tEnter Co-ords (X1,Y1) >> ";
	cin>>x1>>y1;
	cout<<"\n\tEnter Co-ords (X2,Y2) >> ";
	cin>>x2>>y2;
	cout<<"\n\tEnter Co-ords (X3,Y3) >> ";
	cin>>x3>>y3;
	
	glBegin(GL_LINE_LOOP);
		glColor3f(0.5,0.5,0.5);
		glVertex2d(x1,y1);
		glVertex2d(x2,y2);
		glVertex2d(x3,y3);
		glColor3f(0,0,0);		
	glEnd();
	glFlush();
	
	Koch(x1,y1,x3,y3,3);
	Koch(x3,y3,x2,y2,3);
	Koch(x2,y2,x1,y1,3);	
}
 
void Koch(int X1,int Y1,int X2,int Y2,int n)
{
	double lx, ly, x[5], y[5] ,p , q;
	
	lx=(X2-X1)/3;
	ly=(Y2-Y1)/3;
	
	x[0]=X1;		y[0]=Y1;			//point 0
	x[1]=X1+lx;		y[1]=Y1+ly;			//point 1
	x[3]=X2-lx;		y[3]=Y2-ly;;		//point 3
	x[4]=X2;		y[4]=Y2;			//point 4
	
	p=x[3]-x[1];			q=y[3]-y[1];				// point 2 to origin
	x[2]=p*(COS)+q*(SIN);	y[2]=-p*(SIN)+q*(COS);		//rotation
	x[2]=x[2]+x[1];			y[2]=y[2]+y[1];				//inverse transformation
	
	if(n > 0)
	{
		Koch(x[0] , y[0] , x[1] , y[1] ,n-1);
		Koch(x[1] , y[1] , x[2] , y[2] ,n-1);
		Koch(x[2] , y[2] , x[3] , y[3] ,n-1);
		Koch(x[3] , y[3] , x[4] , y[4] ,n-1);
	}
	else
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(0,0,1);	
		 	glVertex2d(x[0] , y[0]);
			glVertex2d(x[1] , y[1] );
			glVertex2d(x[2] , y[2] );
			glVertex2d(x[3] , y[3] );
			glVertex2d(x[4] , y[4] );
			glColor3f(0,0,0);	
		glEnd();
		glFlush();
	}
}
 
void Menu(int choice)
{
	switch(choice)
	{
		case 1:
			Line();
			break;
		case 2:
			Triangle();
			break;
		case 0:
			exit(0);
			break;
	}
}