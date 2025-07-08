 #include <stdio.h>
 #include <math.h>
 #include <GL/glut.h>
 typedef float Matrix4[4][4];
 Matrix4 theMatrix;
 static GLfloat input[5][3] =
 {
 {-30, 30, 0}, {-80, 30, 0}, {-90, 40, -50}, {-40, 40, -50}, {-60, 80, -25}
 };
 float output[5][3];
 float tx, ty, tz;
 float sx, sy, sz;
 float angle, shearValueX, shearValueY;
 int choice, choiceRot;
 void setIdentityM(Matrix4 m)
 {
 for (int i = 0; i < 4; i++)
 for (int j = 0; j < 4; j++)
 m[i][j] = (i == j);
 }
 void translate(float tx, float ty, float tz)
 {
 for (int i = 0; i < 5; i++)
 {
 output[i][0] = input[i][0] + tx;
 output[i][1] = input[i][1] + ty;
 output[i][2] = input[i][2] + tz;
}
 }
 void scale(float sx, float sy, float sz)
 {
 theMatrix[0][0] = -sx;
 theMatrix[1][1] = -sy;
 theMatrix[2][2] = -sz;
 }
 void RotateX(float angle) 
{
 angle = angle * 3.142 / 180;
 theMatrix[1][1] = cos(angle);
 theMatrix[1][2] = -sin(angle);
 theMatrix[2][1] = sin(angle);
 theMatrix[2][2] = cos(angle);
 theMatrix[1][1] = -theMatrix[1][1];
 theMatrix[1][2] = -theMatrix[1][1];
 theMatrix[2][1] = -theMatrix[1][1];
 theMatrix[2][2] = -theMatrix[1][1];
 }
 void RotateY(float angle)
 {
 angle = angle * 3.14 / 180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][2] = -sin(angle);
 theMatrix[2][0] = sin(angle);
 theMatrix[2][2] = cos(angle);
 theMatrix[1][1] = -theMatrix[1][1];
 theMatrix[1][2] = -theMatrix[1][1];
 theMatrix[2][1] = -theMatrix[1][1];
 theMatrix[2][2] = -theMatrix[1][1];
 }
 void RotateZ(float angle) 
{
 angle = angle * 3.14 / 180;
 theMatrix[0][0] = cos(angle);
 theMatrix[0][1] = sin(angle);
 theMatrix[1][0] = -sin(angle);
 theMatrix[1][1] = cos(angle);
 theMatrix[1][1] = -theMatrix[1][1];
 theMatrix[1][2] = -theMatrix[1][1];
 theMatrix[2][1] = -theMatrix[1][1];
 theMatrix[2][2] = -theMatrix[1][1];
 }
void reflect()
 {
 for (int i = 0; i < 5; i++)
 {
 output[i][0] = input[i][0];
 output[i][1] = -input[i][1]; // Reflecting about the X-axis
 output[i][2] = input[i][2];
 }
 }
 void Shear(float shx, float shy)
 {
 for (int i = 0; i < 5; i++)
 {
 output[i][0] = input[i][0] + shx * input[i][1];
 output[i][1] = input[i][1] + shy * input[i][0];
 output[i][2] = input[i][2];
 }
 }
 void multiplyM()
 {
 for (int i = 0; i < 5; i++)
 {
 for (int j = 0; j < 3; j++)
 {
 output[i][j] = 0;
 for (int k = 0; k < 3; k++)
 {
 output[i][j] = output[i][j] + input[i][k] * theMatrix[k][j];
 }
 }
 }
 }
 void Axes(void)
 {
 glBegin(GL_LINES); 
glVertex2s(-1000, 0);
 glVertex2s(1000, 0);
 glEnd();
 glBegin(GL_LINES);
 glVertex2s(0, -1000);
 glVertex2s(0, 1000);
 glEnd();
 }
void draw(float a[8][3])
 {
 glBegin(GL_QUADS);
 glColor3f(0.7, 0.4, 0.5); 
glVertex3fv(a[0]);
 glVertex3fv(a[1]);
 glVertex3fv(a[2]);
 glVertex3fv(a[3]);
 glBegin(GL_QUADS);
 glColor3f(0.8, 0.2, 0.4);
 glVertex3fv(a[3]);
 glVertex3fv(a[4]);
 glVertex3fv(a[2]);
 glBegin(GL_QUADS);
 glColor3f(0.3, 0.6, 0.7); 
glVertex3fv(a[2]);
 glVertex3fv(a[4]);
 glVertex3fv(a[1]);
 glBegin(GL_QUADS);
 glColor3f(0, 0, 0.2);
 glVertex3fv(a[2]);
 glVertex3fv(a[4]);
 glVertex3fv(a[0]);
 glBegin(GL_QUADS);
 glColor3f(0.6, 0.6, 0.2); 
glVertex3fv(a[0]);
 glVertex3fv(a[1]);
 glVertex3fv(a[4]);
 glEnd();
 }
 void init()
 {
 glClearColor(0.1, 0.1, 0.1, 1.0); 
glOrtho(-454.0, 454.0, -250.0, 250.0, -250.0, 250.0);
 }
 void display()
 {
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 Axes();
 draw(input);
 setIdentityM(theMatrix);
 switch (choice)
 {
 case 1:
 translate(tx, ty, tz);
 break;
 case 2:
 scale(sx, sy, sz);
multiplyM();
 break;
 case 3:
 switch (choiceRot)
 {
 case 1:
 RotateX(angle);
 break;
 case 2:
 RotateY(angle);
 break;
 case 3:
 RotateZ(angle);
 break;
 default:
 break;
 }
 multiplyM();
 break;
 case 4:
 reflect();
 break;
 case 5:
 Shear(shearValueX, shearValueY);
 break;
 }
 draw(output);
 glFlush();
 }
 int main(int argc, char** argv)
 {
 glutInit(&argc, argv);
 glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
 glutInitWindowSize(900, 900);
 glutInitWindowPosition(0, 0);
 glutCreateWindow("3D TRANSFORMATIONS");
 init();
 printf("Enter your choice number:\n1.Translation\n2.Scaling\n3.Rotation\
 n4.Reflection\n5.Scaling\n");
 scanf("%d", &choice);
 switch (choice)
 {
 case 1:
 printf("\nEnter Tx, Ty & Tz: \n");
 scanf("%f %f %f", &tx, &ty, &tz);
 break;
 case 2:
 printf("\nEnter Sx, Sy & Sz: \n");
 scanf("%f %f %f", &sx, &sy, &sz);
 break;
case 3:
 printf("Enter your choice for Rotation about axis:\n1.parallel to X-axis."
 "(y& z)\n2.parallel to Y-axis.(x& z)\n3.parallel to Z-axis."
 "(x& y)\n =>");
 scanf("%d", &choiceRot);
 switch (choiceRot)
 {
 case 1:
 printf("\nEnter Rotation angle: ");
 scanf("%f", &angle);
 break;
 case 2:
 printf("\nEnter Rotation angle: ");
 scanf("%f", &angle);
 break;
 case 3:
 printf("\nEnter Rotation angle: ");
 scanf("%f", &angle);
 break;
 default:
 break;
 }
 break;
 case 4: 
break;
 case 5: printf("\nEnter Shearing value along X-axis and Y-Axis: ");
 scanf("%f %f", &shearValueX, &shearValueX);
 break;
 default:
 break;
 }
 glutDisplayFunc(display);
 glutMainLoop();
 return 0;
 }
