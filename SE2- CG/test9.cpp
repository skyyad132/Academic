// Generate fractal patterns by using Koch curves

#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;

#define pi 3.1415

void myKochDisplay();
void myMenu(int);
void init();
void line();
void triangle();
void drawKoch(int x1, int y1, int x2, int y2, int n);

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Fractal pattern by Koch curves");
	init();
	glutDisplayFunc(myKochDisplay);

	glutCreateMenu(myMenu);
		glutAddMenuEntry("Line", 1);
		glutAddMenuEntry("Triangle", 2);
		glutAddMenuEntry("Exit", 3);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	
	glutMainLoop();
}


void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3);
	gluOrtho2D(0, 640, 0, 480);
}


void myKochDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}


void myMenu(int choice)
{
	switch(choice)
	{
		case 1:
			line();
			break;
		case 2:	
			triangle();
			break;
		case 3:
			exit(0);
			break;
	}
}


void line()
{
	float x1, y1, x2, y2;

	cout << "Enter x1, y1 : ";	cin >> x1 >> y1;
	cout << "Enter x2, y2 : ";  cin >> x2 >> y2;

	glBegin(GL_LINE_STRIP);
		glColor3f(0.5, 0.5, 0.5);
			glVertex2d(x1, y1);
			glVertex2d(x2, y2);
		glColor3f(0, 0, 0);
	glEnd();
	glFlush();

	drawKoch(x2, y2, x1, y1, 3);
}


void drawKoch(int x_EndPoint_1, int y_EndPoint_1, int x_EndPoint2, int y_EndPoint_2, int n)
{
	float lx, ly;
	float x[5], y[5];
	float p, q;

	lx = (x_EndPoint2 - x_EndPoint_1) / 3;
	ly = (y_EndPoint_2 - y_EndPoint_1) / 3;

	// point 1
	x[0] = x_EndPoint_1;
	y[0] = y_EndPoint_1;

	// point 2
	x[1] = x_EndPoint_1 + lx;
	y[1] = y_EndPoint_1 + ly;

	// point 3
	x[3] = x_EndPoint2 - lx;
	y[3] = y_EndPoint_2 - ly;

	//point 4
	x[4] = x_EndPoint2;
	y[4] = y_EndPoint_2;


	// point 2 to origin
	p = x[3] - x[1];
	q = y[3] - y[1];

	x[2] =  p*cos(pi/3) + q*sin(pi/3);
	y[2] = -p*sin(pi/3) + q*cos(pi/3);

	x[2] = x[2] + x[1];
	y[2] = y[2] + y[1];

	if (n > 0) // drawing pattern n times
	{
		drawKoch(x[0], y[0], x[1], y[1], n - 1);
		drawKoch(x[1], y[1], x[2], y[2], n - 1);
		drawKoch(x[2], y[2], x[3], y[3], n - 1);
		drawKoch(x[3], y[3], x[4], y[4], n - 1);
	}

	else
	{
		glBegin(GL_LINE_STRIP);
			glColor3f(0, 0, 1);
			glVertex2d(x[0], y[0]);
			glVertex2d(x[1], y[1]);
			glVertex2d(x[2], y[2]);
			glVertex2d(x[3], y[3]);
			glVertex2d(x[4], y[4]);
			glColor3f(0, 0, 0);
		glEnd();
		glFlush();
	}
}


void triangle()
{
	float x1, y1;
	float x2, y2;
	float x3, y3;

	cout << "Enter co-ordinates x1, y1 : "; cin >> x1 >> y1;
	cout << "Enter co-ordinates x2, y2 : "; cin >> x2 >> y2;
	cout << "Enter co-ordinates x3, y3 : "; cin >> x3 >> y3;

	glBegin(GL_LINE_LOOP);
		glColor3f(0.5, 0.5, 0.5);
		glVertex2d(x1, y1);
		glVertex2d(x2, y2);
		glVertex2d(x3, y3);
		glColor3f(0, 0, 0);
	glEnd();
	glFlush();

	// look at the order of giving parameters
	// they are give so that koch curves are outside the triangle
	// 1 -> 3 -> 2 -> 1
	drawKoch(x1, y1, x3, y3, 3);
	drawKoch(x3, y3, x2, y2, 3);
	drawKoch(x2, y2, x1, y1, 3);
}