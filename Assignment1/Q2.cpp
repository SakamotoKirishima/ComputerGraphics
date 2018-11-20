#include<GL/glut.h>
#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
 
//int x1,y1,r;


 

 
void display()
{
   
   glClear (GL_COLOR_BUFFER_BIT);
   glColor3f (1.0, 0.0, 0.0);      
   drawCircle();
 
   glFlush ();                  
}
 
int main(int argc,char** argv)
{
    cout << "Enter center coordinates\n";
    cout << "X-Coordinate: "; cin >> x1;
    cout << "Y-Coordinate: "; cin >> y1;
    cout << "Radius: "; cin >> r;
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1000,1000);
    glutCreateWindow("Question2");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}