 #include <GL/glut.h>
 int width = 800, height = 800;
 void putpixel(int x, int y) {
 glBegin(GL_POINTS);
 glVertex2i(x, y);
 glEnd();
 glFlush();
 }
 void floodfill(int x, int y, float insidecolor[3]) {
 float current[3];
 glReadPixels(x, y, 1, 1, GL_RGB, GL_FLOAT, current);
 if (current[0] != insidecolor[0] || current[1] != insidecolor[1] || current[2] != insidecolor[2])
 {
 putpixel(x, y);
 floodfill(x + 1, y, insidecolor);
 floodfill(x - 1, y, insidecolor);
 floodfill(x, y + 1, insidecolor);
 floodfill(x, y - 1, insidecolor);
 }
 }
 void display() {
 glClearColor(1.0, 0.823, 0.663, 0.0); 
glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 0.0, 1.0);
 glBegin(GL_LINE_LOOP);
 glVertex2i(300, 300);
 glVertex2i(500, 300);
 glVertex2i(500, 500);
 glVertex2i(300, 500);
 glEnd();
 float insidecolor[] = {1.0, 0.0, 1.0};
 floodfill(400, 400, insidecolor);
 glFlush();
}
 int 
main(
 int 
argc, 
char** 
{
 glutInit(
 &argc, 
argv) 
argv);
 glutInitDisplayMode(
 GLUT_SINGLE | 
glutInitWindowSize
 GLUT_RGB);
 (width, height);
 glutCreateWindow(
 "Flood Fill Algorithm");
 gluOrtho2D(0
 , width, 0
 , height);
 glutDisplayFunc(
 display);
 glutMainLoop
 ();
 return 0;
 }
