#include <stdio.h>
 #include <GL/glut.h>
 int xc, yc, rx, ry;
 void display() {
 int x = 0;
 int y = ry;
 int p1 = ry * ry - rx * rx * ry + rx * rx / 4;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1.0, 1.0, 0.0);
 glPointSize(5.0);
 glBegin(GL_POINTS);
 glVertex2i(xc + x, yc + y);
 glVertex2i(xc - x, yc + y);
 glVertex2i(xc + x, yc - y);
 glVertex2i(xc - x, yc - y);
 while (2 * ry * ry * x < 2 * rx * rx * y) {
 if (p1 < 0) {
 x++;
 p1 = p1 + 2 * ry * ry * x + ry * ry;
 } else {
 x++;
 y--;
 p1 = p1 + 2 * ry * ry * x - 2 * rx * rx * y + ry * ry;
 }
 glVertex2i(xc + x, yc + y);
 glVertex2i(xc - x, yc + y);
 glVertex2i(xc + x, yc - y);
 glVertex2i(xc - x, yc - y);
 }
 int p2 = ry * ry * (x + 1 / 2) * (x + 1 / 2) + rx * rx * (y - 1) * (y - 1) - rx * rx * ry * ry;
 while (y >= 0) {
 if (p2 > 0) {
 y--;
 p2 = p2 - 2 * rx * rx * y + rx * rx;
 } else {
 x++;
y--;
 p2 = p2 + 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
 }
 glVertex2i(xc + x, yc + y);
 glVertex2i(xc - x, yc + y);
 glVertex2i(xc + x, yc - y);
 glVertex2i(xc - x, yc - y);
 }
 glEnd();
 glFlush();
 }
 void init(void) {
 glClearColor(0.0, 0.0, 1.0, 0.0);
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glOrtho(-100.0, 100.0, -100.0, 100.0, -1.0, 1.0);
 }
 int main(int argc, char** argv) {
 printf("Enter the center (xc yc) of the ellipse: ");
 scanf("%d %d", &xc, &yc);
 printf("Enter the radii (rx ry) of the ellipse: ");
 scanf("%d %d", &rx, &ry);
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
 glutInitWindowSize(900, 900);
 glutInitWindowPosition(100, 100);
 glutCreateWindow("Ellipse Midpoint Drawing");
 init();
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
 }
