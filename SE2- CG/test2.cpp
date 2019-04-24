/*
Draw the polygons by using the mouse. Choose colors by clicking on the designed color pane. 
Use window port to draw. (Use DDA algorithm for line drawing)
*/

#include <iostream>
#include <math.h>
#include <GL/glut.h>

#define w 500
#define h 500

int k = 0; // for number of vertices of current polygon
float a[30][2] = {0};


void menu(GLint item);
void myMouseFunction(GLint but, GLint st, GLint x, GLint y);
void dda(float x1, float y1, float x2, float y2);

void init() 
{
	glClearColor(1.0, 1.0, 1.0, 0);
	glColor3f(0.0, 0.0, 0.0);
	//glViewport(0, 0, 500, 500);
	glMatrixMode(GL_PROJECTION);
	glPointSize(5);
	glLoadIdentity();
	gluOrtho2D(-w/2, w/2, -h/2, h/2);
	glClear(GL_COLOR_BUFFER_BIT);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Middle -> Left -> Right");
	init();

	glutCreateMenu(menu);
		glutAddMenuEntry("RED", 1);
		glutAddMenuEntry("GREEN", 2);
		glutAddMenuEntry("BLUE", 3);
		glutAddMenuEntry("CYAN", 4);
	glutAttachMenu(GLUT_MIDDLE_BUTTON);

	glutMainLoop();
}

void menu(GLint item)
{
		if (item == 1)
		{
			glColor3f(1.0, 0.0, 0.0);
			glutMouseFunc(myMouseFunction);
		}
		if (item == 2)
		{
			glColor3f(0.0, 1.0, 0.0);
			glutMouseFunc(myMouseFunction);
		}
		if (item == 3)
		{
			glColor3f(0.0, 0.0, 1.0);
			glutMouseFunc(myMouseFunction);
		}
		if (item == 4)
		{
			glColor3f(0.0, 1.0, 1.0);
			glutMouseFunc(myMouseFunction);
		}
}


void myMouseFunction(GLint button, GLint state, GLint x, GLint y)
{
	int i;
	if (state == GLUT_DOWN)
	{
		if (button == GLUT_LEFT_BUTTON)
		{
			a[k][0] = float(x - 250);
			a[k][1] = float(250 - y);
			glBegin(GL_POINTS);
				glVertex2f(a[k][0], a[k][1]);
			glEnd();
			k++;
			glFlush();
		}
		if (button == GLUT_RIGHT_BUTTON)
		{
			for (i = 0; i < k - 1 ; i++)
			{
				dda(a[i][0], a[i][1], a[i+1][0], a[i+1][1]);
			}
			dda(a[i][0], a[i][1], a[0][0], a[0][1]);
			k = 0;
			glFlush();
		}
	}
}


void dda(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;

	float steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

	float xInc = dx / steps;
	float yInc = dy / steps;

	float x = x1, y = y1;

	glBegin(GL_POINTS);
		glVertex2d(x, y);

		for (int i = 1; i < steps; i++)
		{
			x = x + xInc;
			y = y + yInc;
			glVertex2d(floor(x + 0.5), floor(y + 0.5));
		}
	glEnd();
	glFlush();
}


