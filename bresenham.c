 #include<GL/glut.h>
 #include<stdio.h>
 #include<stdlib.h>
 int centerX, centerY, radius;
 void display(void)
 {
 int x=0;
 int y=radius;
 int d=3-2*radius;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 1.0, 0.0);
 glPointSize(5.0);
 glBegin(GL_POINTS);
 glVertex2i(x,y);
 while(x<=y) 
{
 glVertex2i(centerX+x, centerY+y);
 glVertex2i(centerX-x, centerY+y);
 glVertex2i(centerX+x, centerY-y);
 glVertex2i(centerX-x, centerY-y);
 glVertex2i(centerX+y, centerY+x);
 glVertex2i(centerX-y, centerY+x);
 glVertex2i(centerX+y, centerY-x);
 glVertex2i(centerX-y, centerY-x);
 if(d<0)
 {
 d+=4*x+6;
 } else {
 d+=4*(x-y)+10;
 y--;
 }
 x++;
 } while(x<=y);
 glEnd();
 glFlush();
 }
 void init(void)
{
 glClearColor(0.0, 0.0, 1.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }
 int main(int argc, char** argv)
 {
 printf("Enter the X-coordinate of the center: ");
 scanf("%d", &centerX);
 printf("Enter the Y-coordinate of the center: ");
 scanf("%d", &centerY);
 printf("Enter the radius of the circle: ");
 scanf("%d", &radius);
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(900, 900);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Bresenham Circle Drawing");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
 }
