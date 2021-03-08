#include <stdio.h>
#include <GL/glut.h>
#include <math.h>
#include <time.h>



int x = 725,y = 850;//Initial x,y coordinates of the circle

// For intial initialisation of intial window properties
void myInit()
{
    glClearColor(1, 1, 1, 1);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 1000.0, 0.0, 1000.0);
}

void Timer(int value) {
    glutTimerFunc(1000, Timer, value);
    glutPostRedisplay();
}

// Function to draw a circle
void draw_circle(float x, float y, float radius) {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();
    glTranslatef(x, y, 0.0f);
    static const int circle_points = 100;
    static const float angle = 2.0f * 3.1416f / circle_points;

    glBegin(GL_POLYGON);
    double angle1=0.0;
    glVertex2d(radius * cos(0.0) , radius * sin(0.0));
    int i;
    for (i=0; i<circle_points; i++)
    {
        glVertex2d(radius * cos(angle1), radius *sin(angle1));//drawing a smooth line between the points with parametric equations
        angle1 += angle;
    }

    glEnd();
    glPopMatrix();
}

// Function to add delay as per the ques
void delay(float secs)
{
  float end = clock() / CLOCKS_PER_SEC + secs;
  while ((clock() / CLOCKS_PER_SEC) < end);
}


int count = 0;


// function for drawing the rectangles
void drawRectangle()
{
    int w = 150;

    for(int i=200;i<800;i+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(68,114,196);
        glVertex2f(i,i);//vertex coord
        glVertex2f(i,i+w);//vertex coord
        glVertex2f(i+w,i+w);//vertex coord
        glVertex2f(i+w,i);//vertex coord
        glEnd();
    }

    for(int i=350,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(237,125,49);
        glVertex2f(i,j);//vertex coord
        glVertex2f(i,j+w);//vertex coord
        glVertex2f(i+w,j+w);//vertex coord
        glVertex2f(i+w,j);//vertex coord
        glEnd();
    }

    for(int i=500,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(68,114,196);//vertex coord
        glVertex2f(i,j);//vertex coord
        glVertex2f(i,j+w);//vertex coord
        glVertex2f(i+w,j+w);//vertex coord
        glVertex2f(i+w,j);//vertex coord
        glEnd();
    }

    for(int i=650,j = 200;i<800;i+=150,j+=150)
    {
        glBegin(GL_QUADS);
        glColor3ub(112,173,71);
        glVertex2f(i,j);//vertex coord
        glVertex2f(i,j+w);//vertex coord
        glVertex2f(i+w,j+w);//vertex coord
        glVertex2f(i+w,j);//vertex coord
        glEnd();
    }

    glColor3ub(171,171,171);
    draw_circle(x,y,50);

    if(count == 0)
    {
        x-= 35;
        y += 50;

    }
    if(count == 1)
    {
        x-= 35;
        y+= 50;

    }
    if(count == 2)
    {
        x-= 20;
        y-= 50;
    }
    if(count == 3)
    {
        x-= 20;
        y-= 50;
    }
    if(count == 4)
    {
        x-= 20;
        y-= 75;
    }
    if(count == 5)
    {
        x-= 20;
        y-= 75;
    }
    count = (count+1)%6;//for repeatedly moving sphere

}

// Function to render the figure on the screen
void myDisplay()
{
    int n = 25;
    while(n--)
    {
        glClear(GL_COLOR_BUFFER_BIT);
        drawRectangle();
        glEnd();
        glFlush();
        delay(0.01);// adding a delay between frames
    }

}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(1000, 1000);// For the window size
    glutInitWindowPosition(0, 0);//Inital window pos
    glutCreateWindow("Animated Code");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop();
}