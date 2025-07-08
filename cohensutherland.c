 #include<stdio.h>
 #include<GL/glut.h>
 #define outcode int
 double xmin=30,ymin=30,xmax=120,ymax=120;
 double xvmin=200,yvmin =200, xvmax=300,yvmax=300;
 const int RIGHT= 8, LEFT =2, TOP=4, BOTTOM=1; 
outcode funcoutcode(double x,double y); 
void CohenSutherlandLineClipAnddraw(double x0,double y0,double x1,double y1)
 {
 outcode outcode0,outcode1,outcodeOut;
 int accept=0,done=0;
 outcode0=funcoutcode(x0,y0);
 outcode1=funcoutcode(x1,y1);
 do
 {
 if(!(outcode0|outcode1))
 { 
accept=1;
 done=1;
 }
 else
 if(outcode0 & outcode1)done=1;
 else
 {
 double x,y;
 outcodeOut= outcode0?outcode0:outcode1;
if(outcodeOut & TOP) 
{
 x=x0+(x1-x0)*(ymax-y0)/(y1-y0);
 y=ymax;
 }
 else
 if(outcodeOut & BOTTOM)
 {
 x= x0+(x1-x0)*(ymin-y0)/(y1-y0);
 y=ymin;
 }
 else if(outcodeOut & RIGHT)
 {
 y= y0+(y1-y0)*(xmax-x0)/(x1-x0);
 x=xmax;
 }
 else 
{
 y= y0+(y1-y0)*(xmin-x0)/(x1-x0);
 x=xmin;
 }
 if(outcodeOut == outcode0) 
{ x0=x; 
y0=y;
 outcode0 = funcoutcode(x0,y0);
 }
 else 
{ 
x1=x;
 y1=y;
 outcode1 = funcoutcode(x1,y1);
 }
 }
 }while(!done);
 if(accept)
 {
 double sx=(xvmax-xvmin)/(xmax-xmin);
 double sy=(yvmax-yvmin)/(ymax-ymin);
 double vx0 = xvmin+(x0-xmin)*sx;
 double vy0 = yvmin+(y0-ymin)*sy;
 double vx1 = xvmin+(x1-xmin)*sx;
 double vy1 = yvmin+(y1-ymin)*sy;
 glColor3f(1.0,0.0,0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2f(xvmin,yvmin);
 glVertex2f(xvmax,yvmin);
 glVertex2f(xvmax,yvmax);
 glVertex2f(xvmin,yvmax);
 glEnd();
glColor3f(0.0,1.0,0.0);
 glBegin(GL_LINES);
 glVertex2d(vx0,vy0);
 glVertex2d(vx1,vy1);
 glEnd();
 }
 }
 outcode funcoutcode(double x,double y)
 {
 outcode code=0;
 if(y>ymax)code|=TOP;
 if(y<ymin)code|=BOTTOM; 
if(x>xmax)code|=RIGHT; 
if(x<xmin)code|=LEFT;
 return code;
 }
 void display()
 {
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0,0.0,0.0); 
glLineWidth(3.0);
 glBegin(GL_LINES);
 glVertex2d(150,10);
 glVertex2d(40,150);
 glVertex2d(60,20);
 glVertex2d(80,180);
 glEnd();
 glColor3f(1.0,0.0,0.0); 
glBegin(GL_LINE_LOOP);
 glVertex2f(xmin,ymin);
 glVertex2f(xmax,ymin);
 glVertex2f(xmax,ymax);
 glVertex2f(xmin,ymax);
 glEnd();
 CohenSutherlandLineClipAnddraw(150,10,40,150);
 CohenSutherlandLineClipAnddraw(60,20,80,180);
 glFlush();
 }
 void myinit()
 {
 glClearColor(1.0, 0.75, 0.80,0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,499.0,0.0,499.0);
 }
 int main(int argc, char** argv)
 {
 glutInit(&argc,argv);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutInitWindowSize(800,800);
glutInitWindowPosition(0,0
 );
 glutCreateWindow(
 "cohen Sutherland line clipping algorithm"
 glutDisplayFunc(
 display
 );
 myinit
 ();
 glutMainLoop
 return 0;
 }
