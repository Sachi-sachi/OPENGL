#include<stdlib.h> 
#include<stdio.h> 
#include <GL/gl.h> 
#include <GL/glut.h> 
float x1[3], x2[3], y3[3], y4[3]; 
void display(void) { 
for(int i=0;i<3;i++) 
{ 
float dy, dx, step, x, y, k, Xin, Yin; 
dx=x2[i]-x1[i]; 
dy=y4[i]-y3[i]; 
if(abs(dx)>abs(dy)) 
step= abs(dx); 
else 
step=abs(dy); 
Xin=dx/step; 
Yin=dy/step; 
x=x1[i]; 
y=y3[i]; 
glBegin(GL_POINTS); 
glVertex2i(x, y); 
glEnd(); 
for(k=1;k<=step;k++) 
{ 
x=x+Xin; 
y=y+Yin; 
glBegin(GL_POINTS); 
glVertex2i(x, y); 
glEnd(); 
} 
} 
glFlush(); 
} 
void myInit (void) { 
glClearColor(0.0, 0.0, 0.0, 0.0); 
glMatrixMode(GL_PROJECTION); 
glLoadIdentity(); 
gluOrtho2D(0.0, 640.0, 0.0, 480.0); 
} 
int main(int argc, char ** argv) { 
for(int i=0;i<3;i++) 
{ 
printf("Value of x1: "); 
scanf("%f", &x1[i]); 
printf("Value of y1: "); 
scanf("%f", &y3[i]); 
printf("Value of x2: "); 
scanf("%f", &x2[i]); 
printf("Value of y2: "); 
scanf("%f", &y4[i]); 
} 
glutInit( & argc, argv); 
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
glutInitWindowSize(1000, 1000); 
glutInitWindowPosition(100, 150); 
glutCreateWindow(""); 
myInit(); 
glutDisplayFunc(display); 
glutMainLoop(); 
}
