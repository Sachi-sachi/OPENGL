 #include <GL/glut.h>
 #include <stdio.h>
 #include <math.h>
 #define XMIN 50
 #define XMAX 300
 #define YMIN 50
 #define YMAX 200
 float x1, y4, x2, y2;
 void init() {
 glClearColor(0.7176, 0.4431, 0.4667, 1.0);
 glColor3f(0.0, 0.0, 0.0);
 gluOrtho2D(0, 400, 0, 400);
 }
 void drawLine(float x1, float y4, float x2, float y2) {
 glBegin(GL_LINES);
 glVertex2f(x1, y4);
 glVertex2f(x2, y2);
 glEnd();
 }
 void cyrusBeckClipping() 
{
 float dx=x2-x1;
 float dy=y2-y4;
 float t1=0, t2=1;
 float p[4]={ -dx, dx, -dy, dy };
 float q[4]={ x1 - XMIN, XMAX - x1, y4 - YMIN, YMAX - y4 };
 for (int i=0; i<4; i++) 
{
 if(p[i]==0) 
{
 if (q[i]<0)return; 
}
 else 
{
 float t=q[i]/p[i];
 if(p[i]<0) 
{
if (t>t2)return; 
else if(t>t1)t1=t; 
}
 else 
{
 if(t<t1)return; 
else if(t<t2)t2=t;
 }
 }
 }
 float clippedX1=x1+t1*dx;
 float clippedy4=y4+t1*dy;
 float clippedX2=x1+t2*dx;
 float clippedY2=y4+t2*dy;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(0.0, 0.0, 0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(XMIN, YMIN);
 glVertex2f(XMIN, YMAX);
 glVertex2f(XMAX, YMAX);
 glVertex2f(XMAX, YMIN);
 glEnd();
 glColor3f(1.0, 0.0, 0.0);
 drawLine(x1, y4, x2, y2);
 glColor3f(0.0, 1.0, 0.0);
 drawLine(clippedX1, clippedy4, clippedX2, clippedY2);
 glFlush();
 }
 void display() 
{
 glClear(GL_COLOR_BUFFER_BIT);
 glLineWidth(3.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(XMIN, YMIN);
 glVertex2f(XMIN, YMAX);
 glVertex2f(XMAX, YMAX);
 glVertex2f(XMAX, YMIN);
 glEnd();
 drawLine(x1, y4, x2, y2);
 cyrusBeckClipping();
 glFlush();
 }
 int main(int argc, char** argv) 
{
 printf("Enter x1, y4, x2, y2: ");
 scanf("%f%f%f%f", &x1, &y4, &x2, &y2);
 glutInit(&argc, argv);
glutInitDisplayMode(
 GLUT_SINGLE | 
GLUT_RGB
 );
 glutInitWindowSize(
 600);
 glutInitWindowPosition(
 600, 
100, 
100);
 glutCreateWindow(
 "Cyrus-Beck Line Clipping Algorithm"
 init
 ();
 glutDisplayFunc(
 glutMainLoop
 ();
 return 0;
 }
