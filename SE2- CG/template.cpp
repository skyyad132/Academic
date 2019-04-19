#include <iostream>
#include <GL/glut.h>

void myDisplay() 
{
	glClear(GL_COLOR_BUFFER_BIT);

	glBegin(GL_LINES);
		glVertex2d(20, 20);
		glVertex2d(200, 200);
	glEnd();
	glFlush();
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

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Satyam Yeah!");
	Init();
	glutDisplayFunc(myDisplay);
	glFlush();
	glutMainLoop();
}