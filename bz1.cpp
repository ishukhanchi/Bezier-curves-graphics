
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.1415926536

void clip(float,float,float);

float xc[100],yc[100],t=0,c=0.0002;

static int n=4,r=3;
float k=9;
void line(float a, float b, float c, float d)
{
   
    glBegin(GL_LINES); 
    glVertex2f(a,b);
    glVertex2f(c,d);     
       glEnd();
    glutPostRedisplay();
    glFlush();
   
   
}
void plot_point(float a, float b)
{
   
    glBegin(GL_POINTS); 
    glVertex2f(a,b);    
       glEnd();
    glFlush();
     glutPostRedisplay();
   
   
}
void foo(int i,float x0, float y0,float x_prev,float y_prev){
    float a,b;
    if(i<r)
    {a=(k*x0+x_prev)/(k+1);
    b=(k*y0+y_prev)/(k+1);
    x0=a;
    y0=b;
    k-=1;
    }

}

void coords(int x0,int y0,int x1,int y1,int x2,int y2,int x3,int y3){
	float x,y;
    while(t<=1)
    {
    x=(x0*(1-t)*(1-t)*(1-t))+(3*x1*(1-t)*(1-t)*t)+(3*t*t*(1-t)*x2)+(t*t*t*x3);
    y=(y0*(1-t)*(1-t)*(1-t))+(3*y1*(1-t)*(1-t)*t)+(3*t*t*(1-t)*y2)+(t*t*t*y3);   
    t+=c;
    plot_point(x,y);
    }   
    t=0;
}

void petal()
{
glColor3f(1,1,1);
glBegin(GL_LINE_LOOP);
glVertex2f(-110,110);
glVertex2f(110,110);
glVertex2f(110,-110);
glVertex2f(-110,-110);
glFlush();
glEnd();

glColor3f(1,0,0);
//coords(-20,0,-130,130,-50,50,10,65);
coords(-5,0,-130,130,130,130,5,0);
coords(0,5,130,130,130,-130,0,-5);
coords(-5,0,-130,-130,130,-130,5,0);
coords(0,5,-130,130,-130,-130,0,-5);

glColor3f(0,1,0);
coords(-2,0,-110,110,110,110,2,0);
coords(0,2,110,110,110,-110,0,-2);
coords(-2,0,-110,-110,110,-110,2,0);
coords(0,2,-110,110,-110,-110,0,-2);

glColor3f(0,0,1);
coords(-2,0,-90,90,90,90,2,0);
coords(0,2,90,90,90,-90,0,-2);
coords(-2,0,-90,-90,90,-90,2,0);
coords(0,2,-90,90,-90,-90,0,-2);

//coords(-20,0,-130,-130,-50,-50,10,-65);
glFlush();
}


void init()
{
    glClearColor(0, 0, 0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250,250);
}
void keypress(unsigned char key,int x, int y){
    t=0;
    glClear(GL_COLOR_BUFFER_BIT);
    if(key=='i'){
    glClearColor(0, 0, 0,0);
    glClear(GL_COLOR_BUFFER_BIT);
    petal();

}
}
int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(30, 50);
    glutInitWindowSize(500, 500);   
    glutCreateWindow("Flower");
    init();
    
    glutKeyboardFunc(keypress);
    glutMainLoop();
    return 0;
}
    