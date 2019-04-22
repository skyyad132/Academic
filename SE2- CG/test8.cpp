#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define RADDEG 57.2957f
void redraw();
void drawBox();
void triad();
void myKeyboardFunction(unsigned char key, int x, int y);
void mySpecialKeys(int key, int x, int y);

float x_AxisEndPoint[3] = { 1, 0, 0 }; //x axis end point
float y_AxisEndPoint[3] = { 0, 1, 0 }; //y axis end point
float z_AxisEndPoint[3] = { 0, 0, 1 }; //z axis end point
float originCoordinate[3] = { 0, 0, 0 }; //origin

GLfloat upAndDownAngle = 0;
GLfloat leftAndRightAngle = 0;
GLfloat translateIn_x_y_z[3] = {0.1, 0.1, 0.1};

GLfloat x_RotateAngle = 0.0;
GLfloat y_RotateAngle = 0.0;
GLfloat z_RotateAngle = 0.0;

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitWindowSize(900 ,600);
    glutInitWindowPosition(300, 300);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("3D cube rotation");

    glutDisplayFunc(redraw);
    
    glutKeyboardFunc(myKeyboardFunction);
    glutSpecialFunc(mySpecialKeys);

    glMatrixMode(GL_PROJECTION);
    gluPerspective(60, 1.5, 1, 10);
    glMatrixMode(GL_MODELVIEW);
 
    glutMainLoop();

}


void redraw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glLoadIdentity();

    glTranslatef(0, 0, -3);

    // following will rotate everything in left and right
    glRotatef(upAndDownAngle, 1, 0, 0); // up and down (abt x)
    glRotatef(leftAndRightAngle, 0, 1, 0); // left and right (abt z)

    triad(); // drawing the axis

    glTranslatef(translateIn_x_y_z[0], translateIn_x_y_z[1], translateIn_x_y_z[2]);

    //rotate abt x, y, z without rotating axis

    glScalef(0.2, 0.2, 0.2);
    glRotatef(x_RotateAngle, 1, 0, 0);
    glRotatef(y_RotateAngle, 0, 1, 0);
    glRotatef(z_RotateAngle, 0, 0, 1);

    drawBox();
    
    glutSwapBuffers();
}


void drawBox()
{
    glBegin(GL_QUADS);
        glColor3f(0.0, 0.7, 0.1); // Front - green
            glVertex3f(-1.0, 1.0, 1.0);
            glVertex3f(1.0, 1.0, 1.0);
            glVertex3f(1.0, -1.0, 1.0);
            glVertex3f(-1.0, -1.0, 1.0);

        glColor3f(0.9, 1.0, 0.0); // Back  - yellow
            glVertex3f(-1.0, 1.0, -1.0);
            glVertex3f(1.0, 1.0, -1.0);
            glVertex3f(1.0, -1.0, -1.0);
            glVertex3f(-1.0, -1.0, -1.0);

        glColor3f(0.2, 0.2, 1.0); // Top - blue
            glVertex3f(-1.0, 1.0, 1.0);
            glVertex3f(1.0, 1.0, 1.0);
            glVertex3f(1.0, 1.0, -1.0);
            glVertex3f(-1.0, 1.0, -1.0);

        glColor3f(0.7, 0.0, 0.1); // Bottom - red
            glVertex3f(-1.0, -1.0, 1.0);
            glVertex3f(1.0, -1.0, 1.0);
            glVertex3f(1.0, -1.0, -1.0);
            glVertex3f(-1.0, -1.0, -1.0);
    glEnd();

}


void triad()
{
    glColor3f(1.0, 1.0, 1.0); // axis of white color

    glBegin(GL_LINES);
        glVertex3fv(originCoordinate);
        glVertex3fv(x_AxisEndPoint); // x axis

        glVertex3fv(originCoordinate);
        glVertex3fv(y_AxisEndPoint); // y axis

        glVertex3fv(originCoordinate);
        glVertex3fv(z_AxisEndPoint); // z axis
    glEnd();

    glRasterPos3f(1.1, 0.0, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'X');

    glRasterPos3f(0.0, 1.1, 0.0);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Y');

    glRasterPos3f(0.0, 0.0, 1.1);
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, 'Z');
}


void myKeyboardFunction(unsigned char key, int x, int y) // rotate 
{
    switch (key)
    {
        case 'x' : 
            x_RotateAngle += 5;
            break;
        case 'y' : 
            y_RotateAngle += 5; 
            break;
        case 'z' : 
            z_RotateAngle += 5;
            break;
        case 'a' : 
            translateIn_x_y_z[0] += 0.1; // translate 
            break;
        case 's':
            translateIn_x_y_z[1] += 0.1; // translate
            break;
        case 'd' : 
            translateIn_x_y_z[2] += 0.1;
            break; 
    }
    glutPostRedisplay();
}


void mySpecialKeys(int key, int x, int y)
{
    switch(key)
    {
        case GLUT_KEY_LEFT:
            leftAndRightAngle -= 5;
            break;

        case GLUT_KEY_RIGHT:
            leftAndRightAngle += 5;
            break;

        case GLUT_KEY_UP:
            upAndDownAngle -= 5;
            break;

        case GLUT_KEY_DOWN:
            upAndDownAngle += 5;
            break;
    }
    glutPostRedisplay();
}