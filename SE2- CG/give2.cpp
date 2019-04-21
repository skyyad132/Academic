
#include <iostream>
#include <GL/glut.h>
#include <math.h>
#define w 500
#define h 500

using namespace std;
float a[30][2];
int k = 0;

void myMouse(GLint button, GLint state, GLint x, GLint y)
{
    if (state == GLUT_DOWN) {
        if (button == GLUT_LEFT_BUTTON) {
            a[k][0] = (float)(x - 250);
            a[k][1] = (float)(250 - y);

            glBegin(GL_POINTS);
            glVertex2f(a[k][0], a[k][1]);
            glEnd();
            k++;
            glFlush();
        }
        if (button == GLUT_RIGHT_BUTTON) {
            glBegin(GL_LINE_LOOP);
            for (int i = 0; i < k; i++) {
                glVertex2f(a[i][0], a[i][1]);
            }
            glEnd();
            k = 0;
            glFlush();
        }
    }
}
void menu(GLint item)
{
    if (item == 1) {
        glColor3f(1.0, 0.0, 0.0);
        glutMouseFunc(myMouse);
    }
    if (item == 2) {
        glColor3f(0.0, 1.0, 0.0);
        glutMouseFunc(myMouse);
    }
    if (item == 3) {
        glColor3f(0.0, 0.0, 1.0);
        glutMouseFunc(myMouse);
    }
    if (item == 4) {
        glColor3f(0.0, 1.0, 1.0);
        glutMouseFunc(myMouse);
    }
}

void myInit()
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glPointSize(5);
    glLoadIdentity();
    gluOrtho2D(-w / 2, w / 2, -h / 2, h / 2);
    glClear(GL_COLOR_BUFFER_BIT);
}
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("POLYGON(First Middle Click->Then LEft Clicks->Then Right Clicks)");
    myInit();
    glutCreateMenu(menu);
    glutAddMenuEntry("RED", 1);
    glutAddMenuEntry("GREEN", 2);
    glutAddMenuEntry("BLUE", 3);
    glutAddMenuEntry("CYAN", 4);
    glutAttachMenu(GLUT_MIDDLE_BUTTON);
    glutMainLoop();
}


Format!Style:
C++ online code formatter © 2014 by KrzaQ

Powered by vibe.d, the D language and clang-format