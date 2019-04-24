/*
Draw inscribed and Circumscribed circles in the triangle as shown as an example below.(Use
any Circle drawing and Line drawing algorithms)
*/

#include <iostream>
#include <math.h>
#include <GL/glut.h>

using namespace std;

#define pi 3.1415;
int x, y, r;
void dda(double x1, double yy1, double x2, double y2);
void display();
void Init();
void bcircle(int x, int y, int r);
void mcircle(int x, int y, int r);
void octant(int, int);


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);

	cout << "Enter x origin, Enter y origin : "; cin >> x >> y;
	cout << "Enter radius : "; 				   ; cin >> r;

	glutCreateWindow("Circle");
	Init();
	glutDisplayFunc(display);
	glutMainLoop();
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	int newr = r/sin(3.1415/6);
	int base = r/tan(3.1415/6);

	bcircle(x, y, r);
	mcircle(x, y, newr);

	dda(x, y - r, x + base, y - r);
	dda(x, y - r, x - base, y - r);
	dda(x - base, y - r, x , y + newr);
	dda(x + base, y - r, x, y + newr);
}

void Init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, 640, 0, 480);
}

void bcircle(int x, int y, int r)
{
	double sum = 3 - 2 * r;
	int xn = 0, yn = r;

	while (xn <= yn)
	{
		if (sum <= 0)
		{
			xn = xn + 1;
			yn = yn;
			sum = sum + 4 * xn + 6;
		}
		else 
		{
			xn = xn + 1;
			yn = yn - 1;
			sum = sum + 4 * (xn - yn) + 10;
		}
		octant(xn, yn);
	}
}

void mcircle(int x, int y, int r)
{
	double p;
	int xn = 0, yn = r;
	p = pow(xn + 1, 2) + pow(yn - 0.5, 2) - pow(r, 2);

	while (xn <= yn)
	{
		if (p <= 0)
		{
			xn = xn + 1;
			yn = yn;
			p = p + 2*xn + 1;
		}
		else
		{
			xn = xn + 1;
			yn = yn - 1;
			p = p + 2*xn - 2*yn;
		}
		octant(xn, yn);
	}
}

void octant(int xn, int yn)
{
	glBegin(GL_POINTS);
		glVertex2d(x + xn, y + yn);
		glVertex2d(x + xn, y - yn);
		glVertex2d(x - xn, y + yn);
		glVertex2d(x - xn, y - yn);

		glVertex2d(x + yn, y + xn);
		glVertex2d(x + yn, y - xn);
		glVertex2d(x - yn, y - xn);
		glVertex2d(x - yn, y + xn);
	glEnd();
	glFlush();
}

void dda(double x1, double yy1, double x2, double y2) {
  double dx = (x2 - x1), dy = (y2 - yy1), steps, xInc, yInc;

  if (abs(dx) >= abs(dy))
    steps = abs(dx);
  else
    steps = abs(dy);

  xInc = dx / steps;
  yInc = dy / steps;

  glBegin(GL_POINTS);

  for (int k = 0; k <= steps; k++, x1 = x1 + xInc, yy1 = yy1 + yInc)
    glVertex2d(x1, yy1);

  glEnd();
  glFlush();
}