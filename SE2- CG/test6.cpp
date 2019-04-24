#include <iostream>
using namespace std;
#include <math.h>
#include <GL/glut.h>

typedef struct
{
    float x;
    float y;
} PT;

PT p1; // bottom-left corner of view rectangle
PT p2; // top-right cornero of view rectangle
int n; // number of vertex
PT p[20]; // given polygon vertices list before clipping
PT pp[20]; // for modified polygon temporary
int i, j;
void myDisplay();
void init();
void myMouse(int, int, int, int);
void left();
void right();
void bottom();
void top();
void drawPolygon();


int main(int argc, char** argv)
{
	int i;
	cout << "\nEnter Coordinates for clipping rectange : ";
    cout << "\nEnter (Xmin, Ymin) : ";
    cin >> p1.x >> p1.y;

    cout << "\nEnter (Xmax, Ymax) : ";
    cin >> p2.x >> p2.y;

    cout << "\nEnter number of vertices : ";
    cin >> n;

    for (i = 0; i < n; i++) 
    {
        cout << "\nEnter coordinates of the vertex : ";
        cout << i + 1;
        cout << "\nEnter (x, y) : ";
        cin >> p[i].x >> p[i].y;
    }
    p[i].x = p[0].x;
    p[i].y = p[0].y; 
    // above to connect the polygons last point to first while drawing

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Polygon clipping");
    init();

    glutDisplayFunc(myDisplay);

    glutMouseFunc(myMouse);

    glutMainLoop();
    return 0;
}


void init()
{
	glClearColor(1.0, 1.0, 1.0, 1);
	glColor3f(0.0, 1.0, 0.0);
	glPointSize(5.0);
	gluOrtho2D(0, 650, 0, 650);
}


void myDisplay()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glBegin(GL_LINE_LOOP);
		glVertex2f(p1.x, p1.y);
		glVertex2f(p1.x, p2.y);
		glVertex2f(p2.x, p2.y);
		glVertex2f(p2.x, p1.y);
	glEnd();

	drawPolygon();

	glFlush();
}


void drawPolygon()
{
	int i;
    for (i = 0; i < n - 1; i++) 
    {
        glBegin(GL_LINES);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2d(p[i].x, p[i].y);
        glVertex2d(p[i + 1].x, p[i + 1].y);
        glEnd();
    }
    glBegin(GL_LINES);
        glVertex2d(p[i].x, p[i].y);
        glVertex2d(p[0].x, p[0].y);
    glEnd();

    glFlush();
}



void myMouse(int button, int state, int x, int y)
{
	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		glClear(GL_COLOR_BUFFER_BIT);

        // draw clipping rectangle
        glBegin(GL_LINE_LOOP);
	        glColor3f(0.0, 1.0, 0.0);
	        glVertex2f(p1.x, p1.y);
	        glVertex2f(p2.x, p1.y);
	        glVertex2f(p2.x, p2.y);
	        glVertex2f(p1.x, p2.y);
        glEnd();

        // clip the polygon
		left();
		right();
		top();
		bottom();

        // draw the polygon after clipping
		drawPolygon();
	}
	glFlush();
}


// don't forget <= or >= when comparing with i+1 point
void left() //LEFT BOUNDARY CLIPPING ALGO
{
    i = 0;
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].x < p1.x && p[i + 1].x >= p1.x) {
            if (p[i + 1].x - p[i].x != 0) {
                pp[j].y = (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p1.x - p[i].x) + p[i].y;
            }
            else {
                pp[j].y = p[i].y;
            }
            pp[j].x = p1.x;
            j++;
            pp[j].x = p[i + 1].x;
            pp[j].y = p[i + 1].y;
            j++;
        }

        if (p[i].x > p1.x && p[i + 1].x >= p1.x) {
            pp[j].y = p[i + 1].y;
            pp[j].x = p[i + 1].x;
            j++;
        }

        if (p[i].x > p1.x && p[i + 1].x <= p1.x) {
            if (p[i + 1].x - p[i].x != 0) {
                pp[j].y = (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p1.x - p[i].x) + p[i].y;
            }
            else {
                pp[j].y = p[i].y;
            }
            pp[j].x = p1.x;
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

void right() //RIGHT BOUNDARY CLIPPING ALGO
{
    i = 0;
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].x > p2.x && p[i + 1].x <= p2.x) {
            if (p[i + 1].x - p[i].x != 0) {
                pp[j].y = (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p2.x - p[i].x) + p[i].y;
            }
            else {
                pp[j].y = p[i].y;
            }
            pp[j].x = p2.x;
            j++;
            pp[j].x = p[i + 1].x;
            pp[j].y = p[i + 1].y;
            j++;
        }
        if (p[i].x < p2.x && p[i + 1].x <= p2.x) {
            pp[j].y = p[i + 1].y;
            pp[j].x = p[i + 1].x;
            j++;
        }
        if (p[i].x < p2.x && p[i + 1].x >= p2.x) {
            if (p[i + 1].x - p[i].x != 0) {
                pp[j].y = (p[i + 1].y - p[i].y) / (p[i + 1].x - p[i].x) * (p2.x - p[i].x) + p[i].y;
            }
            else {
                pp[j].y = p[i].y;
            }
            pp[j].x = p2.x;
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}

void bottom() //BOTTOM BOUNDARY CLIPPING ALGO
{
    i = 0; 
    j = 0;

    for (i = 0; i < n; i++)
    {
        if(p[i].y < p1.y && p[i+1].y >= p1.y)
        {
            if (p[i].x - p[i+1].x != 0)
            {
                pp[j].x = (p1.y - p[i].y) / ((p[i].y - p[i+1].y) / (p[i].x - p[i+1].x)) + p[i].x;
            }
            else
            {
                pp[j].x = p[i].x;
            }
            pp[j].y = p1.y;
            j++;
            pp[j].x = p[i+1].x;
            pp[j].y = p[i+1].y;
            j++;
        }

        if (p[i].y > p1.y && p[i+1].y >= p1.y)
        {
            pp[j].x = p[i+1].x;
            pp[j].y = p[i+1].y;
            j++;
        }

        if (p[i].y > p1.y && p[i+1].y <= p1.y)
        {
            if (p[i].x - p[i+1].x != 0)
            {
                pp[j].x = (p1.y - p[i].y) / ((p[i].y - p[i+1].y) / (p[i].x - p[i+1].x)) + p[i].x;
            }
            else
            {
                pp[j].x = p[i].x;
            }  
            pp[j].y = p1.y;
            j++;          
        }
    }
    for (i = 0; i < n; i++)
    {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;    
}

void top() //ABOVE BOUNDARY CLIPPING ALGO
{
    i = 0;
    j = 0;
    for (i = 0; i < n; i++) {
        if (p[i].y > p2.y && p[i + 1].y <= p2.y) {
            if (p[i + 1].y - p[i].y != 0) {
                pp[j].x = (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p2.y - p[i].y) + p[i].x;
            }
            else {
                pp[j].x = p[i].x;
            }
            pp[j].y = p2.y;
            j++;
            pp[j].x = p[i + 1].x;
            pp[j].y = p[i + 1].y;
            j++;
        }
        if (p[i].y < p2.y && p[i + 1].y <= p2.y) {
            pp[j].y = p[i + 1].y;
            pp[j].x = p[i + 1].x;
            j++;
        }
        if (p[i].y < p2.y && p[i + 1].y >= p2.y) {
            if (p[i + 1].y - p[i].y != 0) {
                pp[j].x = (p[i + 1].x - p[i].x) / (p[i + 1].y - p[i].y) * (p2.y - p[i].y) + p[i].x;
            }
            else {
                pp[j].x = p[i].x;
            }
            pp[j].y = p2.y;
            j++;
        }
    }

    for (i = 0; i < j; i++) {
        p[i].x = pp[i].x;
        p[i].y = pp[i].y;
    }
    p[i].x = pp[0].x;
    p[i].y = pp[0].y;
    n = j;
}