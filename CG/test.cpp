
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <iostream>
using namespace std;
#include <stdlib.h>
#include <math.h>

//defining constants
#define MAX_WIDTH 500
#define MAX_HEIGHT 500

int flag = 1;
float x1 = 0, y1 = 0, x2 = 0, y2 = 0;

void drawPixel(float x, float y)
{

    x = x / (MAX_WIDTH / 2);
    y = y / (MAX_HEIGHT / 2);

    glBegin(GL_POINTS);
    //setting the pointer color
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(x, y);

    glEnd();
    glFlush();
}

//dda implementation
void dda(float m1, float n1, float m2, float n2)
{

    float step, Dx, Dy;
    float dx, dy, length;

    int i = 1;

    dx = dy = length = 0.0;
    step = Dx = Dy = 0.0;

    dx = m2 - m1;
    dy = n2 - n1;
    step = dy / dx;

    cout << m1 << "\t" << n1 << "\t" << m2 << "\t" << n2 << endl;

    length = (dx >= dy) ? dx : dy;
    cout << length << endl;

    Dx = dx / length;
    Dy = dy / length;

    drawPixel(round(m1), round(n1));
    cout << m1 << m2 << endl;

    for (; i <= length; i++)
    {
        m1 = m1 + Dx;
        n1 = n1 + Dy;
        drawPixel(round(m1), round(n1));
        cout << m1 << m2 << endl;
    }
}

void Init()
{
    glClearColor(0.0, 0.0, 0.0, 0);
    glPointSize(2);
    gluOrtho2D(-320, 320, -240, 240);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    dda(-200, -200, 0, 0);
    dda(0, 0, 100, 50);
    glFlush();
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(MAX_WIDTH, MAX_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("DDA Assignment");

    Init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}
