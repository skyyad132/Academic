/*
Implement translation, sheer, rotation and scaling transformations on equilateral triangle and rhombus.
*/

#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;
#define MAX 10
int n, tx, ty, sx, sy, angle, z, xm, ym, shx, shy;
float a[MAX][3]; //Original. in the form of x--y--1
float b[3][3]; //transformation matrix
float c[MAX][3]; //Matrix after doing transformations


void init();
void askUser();
void accept();
void trans();
void mul();
void axis();
void lineDDA(int x0, int y0, int xEnd, int yEnd);
void show();
void scal();
void rot();
void shear();
void rotRef();
void ref();


int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Transformations");
	init();
	
	askUser();

	//glutDisplayFunc(show);
	
	glutMainLoop();
	return 0;
}

void init()
{	
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0, 0.0, 0.0);
	glViewport(0, 0, 640, 480);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glPointSize(1.0f);
	gluOrtho2D(0, 640, 0, 480);
}

void askUser()
{
	int choice;

	cout << "Enter number of vertices : ";
	cin >> n;

	accept();
	do
	{
		cout << "1.Translation\n2.Scaling\n3.Rotation\n4.Rotation about arbitrary\n5.Shearing\n6.Reflection\n9.Exit\n";
		cin >> choice;
		switch(choice)
		{
			case 1:
				cout << "The polygon before translation";
				cout << "Enter the Tx : ";
				cin >> tx;
				cout << "Enter the Ty : ";
				cin >> ty;

				trans(); //create the translation matrix with tx and ty
				mul();   //create the transformed matrix
				show();  //show before and after
				break;

			case 2:
				cout << "Enter the sx : ";
				cin >> sx;
				cout << "Enter the sy : ";
				cin >> sy;

				scal(); //fing the scaling matrix
				mul(); // multiply original with scaling matrix
				show(); // show original and transformed matrix
				break;

			case 3:
				cout << "Enter the angle : ";
				cin >> angle;
				cout << "Press 1 for anticlockwise and 2 for clockwise : ";
				cin >> z;

				rot();
				mul();
				show();
				break;

			case 4:
				cout << "Enter the angle : ";
				cin >> angle;
				cout << "Press 1 for anticlockwise and 2 for clockwise : ";
				cin >> z;
				cout << "Enter x and y of reference axis : ";
				cin >> xm >> ym;

				rotRef();
				mul();
				show();
				break;

			case 5:
				cout << "Enter shx : ";
				cin >> shx;
				cout << "Enter shy : ";
				cin >> shy;

				shear();
				mul();
				show();
				break;

			case 6:
				cout << "\n1.Against X axis\n2.Against Y axis\n3.Against origin\n4.Against Y = X\n5.Against Y = -X";
				cin >> z;

				ref();
				mul();
				show();
				break;

			case 9:
				exit(0);
		}
	}
	while(choice != 9);
}	


void accept()
{
	int i;
	cout << "Enter the coordinates : ";
	for (i = 0; i < n; i++)
	{
		cout << "x : "; cin >> a[i][0];
		cout << "y : "; cin >> a[i][1];
		a[i][2] = 1;
	}

	a[n][0] = a[0][0];
	a[n][1] = a[0][0];
	a[n][2] = 1;
}



/*

					 | 1	0	0 |
translation matrix = | 0	1	0 |
				     |tx   ty   1 |
 
*/
void trans() 
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == j)
			{
				b[i][j] = 1;
			}
			else
			{
				b[i][j] = 0;
			}
		}
	}

	b[2][0] = tx;
	b[2][1] = ty;
}


void mul()
{
	int i, j, k;
	for (i = 0; i < n; i++) // initialize c[][] terms to zero
	{
		for (j = 0; j < 3; j++)
		{
			c[i][j] = 0;
		}
	}

	for (i = 0; i < n; i++) //number of rows is equal to number of vertices
	{
		for (j = 0; j < 3; j++) //maximum of 3 columns
		{
			for (k = 0; k < 3; k++)
			{
				c[i][j] = c[i][j] + a[i][k] * b[k][j];
			}
		}
	}

}


void show()
{
	int i;
	axis();
	glColor3f(1.0, 0.0, 0.0);
	for (i = 0; i < n; i++)
        lineDDA(320 + a[i][0], 240 + a[i][1], 320 + a[(i + 1) % n][0], 240 + a[(i + 1) % n][1]); //homogeneous form

    glColor3f(0.0, 0.0, 1.0);

    //  OUTPUT DATA
    for (i = 0; i < n; i++)
        lineDDA(320 + c[i][0], 240 + c[i][1], 320 + c[(i + 1) % n][0], 240 + c[(i + 1) % n][1]); //homogeneous form
}


void lineDDA(int x0, int y0, int xEnd, int yEnd)
{
    int dx = xEnd - x0;
    int dy = yEnd - y0;
    int steps, k;
    GLfloat xIncrement, yIncrement, x = x0, y = y0;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    xIncrement = GLfloat(dx) / GLfloat(steps);
    yIncrement = GLfloat(dy) / GLfloat(steps);
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (k = 1; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        glBegin(GL_POINTS);
    	glVertex2i(x, y);
    	glEnd();
    }
    glFlush();
}


void axis()
{
    int i, x, y;
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0, 1.0, 1.0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0);
    lineDDA(320, 30, 320, 450); //x axis
    lineDDA(20, 240, 620, 240); //y axis
    glColor3f(0.0, 1.0, 1.0);
    lineDDA(0, 0, 640, 480); //digonal
    lineDDA(0, 480, 640, 0); //digonal

    for (i = -10, x = 20; i <= 10; i++, x += 30) //horizontal line numbering
    {
        glColor3f(0.0, 1.0, 0.0);
        lineDDA(x, 238, x, 242);
    }

    for (i = 7, y = 30; i >= -7; i--, y += 30) //vertical line numbering
    {
        glColor3f(0.0, 1.0, 0.0);
        lineDDA(315, y, 325, y);
    }
}


/*
				  | sx    0     0 |
scaling matrix =  | 0     sy    0 |
				  | 0     0     1 |
*/

void scal()
{
	b[0][0] = sx;
	b[1][1] = sy;

	b[2][2] = 1;
	b[0][1] = b[0][2] = b[1][0] = b[1][2] = b[2][0] = b[2][1] = 0;
}


/*


					| cosX   sinX    0 |
rotation matrix Z = |-sinX   cosX    0 |
					| 0       0      1 |

 

Above matrix is for positive angles. i.e. anticlockwise
if user wants to rotate it in clockwise, we would have to
multiply the angle by -1.
This is done so that user won't have to enter a negative angle
Negative angle means rotation in clockwise
*/

void rot()
{
	int i, j;
	float rAngle;

	if (z == 1) // anticlockwise. Angle same as before
		angle = angle;
	else // clockwise. Angle negated
		angle = angle * (-1);

	// radian = (degree * pi) / 180;
	rAngle = (angle * 3.14) / 180;

	b[0][0] = b[1][1] = cos(rAngle);
	b[0][1] = sin(rAngle);
	b[1][0] = -sin(rAngle);

	b[0][2] = b[1][2] = b[2][0] = b[2][1] = 0;
	b[2][2] = 1;
}

/*

rotation about an arbitrary point xm, ym

transformation matrix about xm, ym by angle X

	| 		cosX    				   sinX		    	  0 |
	|	   -sinX    				   cosX	    	      0 |
	|-xm*cosX + ym*sinX + xm    -xm*sinX - ym*cosX + ym   1 |
*/

void rotRef()
{
	float rAngle;
	int sign;

	if (z == 1) // anticlockwise, no need to change angle
		angle = angle;
	else // clockwise. Negate the angle
		angle = -1 * angle;

	rAngle = (angle*3.14) / 180;

	b[0][0] = b[1][1] = cos(rAngle);
	b[2][2] = 1;
	b[0][1] = sin(rAngle);
	b[1][0] = -sin(rAngle);

	b[2][0] = -xm*cos(rAngle) + ym*sin(rAngle) + xm;
	b[2][1] = -xm*sin(rAngle) - ym*cos(rAngle) + ym;

	b[0][2] = 0;
	b[1][2] = 0;
}

/*
Shearing in x by shx and y by shy

						 |  1     shy    0 |
transformation matrix =  | shx     1     0 |
   						 |  0      0     1 |	

*/
void shear()
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (i == j)
				b[i][j] = 1;
			else
				b[i][j] = 0;
		}
	}

	b[0][1] = shy;
	b[1][0] = shx;
}


/*
Reflection

					  | 1   0   0 |
reflection about x =  | 0  -1   0 |
					  | 0   0   1 |

					  |-1   0   0 |
reflection about y =  | 0   1   0 |
					  | 0   0   1 |

						  |-1   0   0 |
reflection about origin = |	0  -1   0 |
						  |	0   0   1 |

						  | 0   1   0 |
reflection about y = x =  | 1   0   0 |
						  |	0   0   1 |

						  | 0  -1   0 |
reflection about y = -x = |-1   0   0 |
						  |	0   0   1 |				
*/

void ref()
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			b[i][j] = 0;
		}
	}

	b[2][2] = 1;

	switch(z)
	{
		case 1: // reflection about x axis
			b[0][0] = 1;
			b[1][1] = -1;
			break;

		case 2: // reflection about y axis
			b[0][0] = -1;
			b[1][1] = 1;
			break;

		case 3: // reflection about origin
			b[0][0] = -1;
			b[1][1] = -1;
			break;

		case 4: // reflection about y = x
			b[0][1] = 1;
			b[1][0] = 1;
			break;

		case 5: // reflection about y = -x
			b[0][1] = -1;
			b[1][0] = -1;
			break;
	}
}