/*
" I understand how the engines work now. 
  It came to me in a dream. 
  The engines don't move the ship at all. 
  The ship stays where it is and the engines move the universe around it."
?Cubert Farnsworth, Futurama
*/
// I am learning from futurama. Woohoo!

/*
Animation : Implement any one of the following animation assignments,
i) Clock with pendulum
ii) National Flag hoisting
iii) Vehicle/boat locomotion
iv) Falling Water drop into the water and generated waves after impact
v) Kaleidoscope views generation (at least 3 colorful patterns)
*/



#include <iostream>
#include <GL/glut.h>
#include <math.h>


int frame = 0;


void init();
void display();
void doframe(int v);
void car();

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(640,480);

	glutCreateWindow("ANIMATION");
	init();

	glutDisplayFunc(display);

	glutTimerFunc(1000, doframe, 0); // after initial 1000 seconds it will run

	glutMainLoop();
}



void init()
{
	glClearColor(0.6, 0.9, 1, 0);
	glViewport(0, 0, 640, 480);
	gluOrtho2D(0, 640, 0, 480);
}



void display()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0, 0.75, 0); // mountains of green color
	glBegin(GL_TRIANGLES);
		glVertex2d(0, 300);
		glVertex2d(75, 350);
		glVertex2d(150, 300);

		glVertex2d(140, 300);
		glVertex2d(230, 350);
		glVertex2d(300, 300);

		glVertex2d(340, 300);
		glVertex2d(415, 350);
		glVertex2d(490, 300);

		glVertex2d(470, 300);
		glVertex2d(570, 350);
		glVertex2d(640, 300);
	glEnd();

	glColor3f(0.5, 1 , 0.5); // surface of light green
	glBegin(GL_POLYGON);
		glVertex2d(0, 0);
		glVertex2d(0, 300);
		glVertex2d(640, 300);
		glVertex2d(640, 0);
	glEnd();

	glColor3f(0, 1, 1); // river of bluish green
	glBegin(GL_POLYGON);
		glVertex2d(220, 0);
		glVertex2d(300, 300);
		glVertex2d(340, 300);
		glVertex2d(400, 0);
	glEnd();

	glColor3f(0.5, 0.5, 0.5); // road of grey color
	glBegin(GL_POLYGON);
		glVertex2d(0, 120);
		glVertex2d(0, 160);
		glVertex2d(640, 160);
		glVertex2d(640, 120);
	glEnd();

	glColor3f(1, 0, 0.5); // building of pink color
	glBegin(GL_POLYGON);
		glVertex2d(10, 160);
		glVertex2d(10, 260);
		glVertex2d(45, 300);
		glVertex2d(80, 260);
		glVertex2d(80, 160);
	glEnd();

	// push the current matrix
	// so as we translate the universe, current scheme won't
	// car will be placed appropriately according to frame
	// then after popping, background will be same as before, only car moved
	glPushMatrix(); 

	glTranslated((frame % 640) , 0, 0);

	car();

	glPopMatrix();

	glFlush();
}


void doframe(int v)
{
	frame++;
	glutPostRedisplay();
	glutTimerFunc(20, doframe, 0);
}


void car()
{
	glColor3f(0.8, 0.8, 0.8); // body of car dark grey
	glBegin(GL_POLYGON);
		glVertex2d(20, 160);
		glVertex2d(20, 200);
		glVertex2d(100, 200);
		glVertex2d(120, 180);
		glVertex2d(120, 160);
	glEnd();

	glColor3f(0, 0, 0); // window 
	glBegin(GL_LINE_LOOP);
		glVertex2d(80, 200);
		glVertex2d(80, 180);
		glVertex2d(120, 180);
		glVertex2d(100, 200);
	glEnd();

	glColor3f(0, 0, 0); // car body border of black
	glBegin(GL_LINE_LOOP);
	glVertex2d(20, 160);
		glVertex2d(20, 200);
		glVertex2d(100, 200);
		glVertex2d(120, 180);
		glVertex2d(120, 160);
	glEnd();

	glColor3f(0, 0, 0);

	glPushMatrix(); // wheel 1 on left
	glTranslated(30, 160, 0);
	glutWireSphere(5, 110, 110);
	glPopMatrix();

	glPushMatrix();
	glTranslated(110, 160, 0);
	glutWireSphere(5, 110, 110);
	glPopMatrix();

	glFlush();
}