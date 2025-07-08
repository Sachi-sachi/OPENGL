 #include <GL/glut.h>
 void putpixel(int x, int y) 
{
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
 glFlush();
 }
 void edge(int x, int y, float fillcolour[3], float bordercolour[3]) 
{
 float current[3];
 glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, current);
 if(current[0]!=bordercolour[0]||current[1]!=bordercolour[1]||current[2]!=bordercolour[2])
 {
 putpixel(x, y);
 glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, current);
 if(current[0]!=fillcolour[0]||current[1]!=fillcolour[1]||current[2]!=fillcolour[2])
 {
 edge(x+1, y, fillcolour, bordercolour);
 edge(x-1, y, fillcolour, bordercolour);
 edge(x, y+1, fillcolour, bordercolour);
 edge(x, y-1, fillcolour, bordercolour);
 }
 }
 }
 void display() 
{
 glClearColor(1.0, 0.8, 0.6, 1.0);
 glClear(GL_COLOR_BUFFER_BIT);
 float fillcolour[]={0.0, 0.0, 1.0}; 
float bordercolour[]={0.0, 0.0, 0.0}; 
glColor3f(0.0, 0.0, 0.0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(300, 300);
 glVertex2i(600, 300);
 glVertex2i(600, 600);
 glVertex2i(300, 600);
 glEnd();
edge(400, 400, fillcolour, bordercolour);
 glFlush();
 }
 void reshape(int w, int h) 
{
 glViewport(0, 0, (GLsizei)w, (GLsizei)h);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0, (GLdouble)w, 0.0, (GLdouble)h);
 }
 int main(int argc, char **argv) {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(800, 800);
 glutCreateWindow("Edge Fill Algorithm");
 glutDisplayFunc(display);
 glutReshapeFunc(reshape);
 glutMainLoop();
 return 0;
 }
