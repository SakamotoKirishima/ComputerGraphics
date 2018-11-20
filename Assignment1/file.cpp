#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include<cstdio>
#include<string>
 
class Point{
    /*This class is used to store the points in the line*/
public:
    int x, y;
 
    Point(int X,int Y){
        /*Initializes the point*/
        x= X; //x coordinate
        y=Y; //y coordinate
    }
 
    int getx(){
        /*Get x coordinate*/
        return x;
    }
 
    int gety(){
        /* Get y coordinate*/
        return y;
    }
 
    void printPoint(){
        /* Prints the x and y corrdinate*/
        cout << x << ", " << y << '\n';
    }
};
 
class GUI{
private:
    GLFWwindow *window;
    int width, height;
 
    void plotPixel(Point p){
            GLfloat point_array[2]; //The array for each point
            point_array[0]= p.getx();
            point_array[1]= p.gety();
            glVertexPointer(2, GL_FLOAT, 0, point_array);
            glDrawArrays( GL_POINTS, 0, 1 ); // Draw the vertices
    }
public:
   
    GUI(int w, int h){
        width=w;
        height= h;
    }
 
    int GUIStart(){
        if(!glfwInit()) //Initializing glfw
            {
                fprintf(stderr, "Failed to initialize GLFW\n");
                return -1;
            }
        window = glfwCreateWindow(width, height, "Draw A Line", NULL, NULL); //Create window
        if (!window){
            glfwTerminate(); //Error in creating Window
            return -1;
        }
        glfwMakeContextCurrent(window);
        glViewport(0.0f, 0.0f, width, height); //Configure the coordinate system
        glMatrixMode(GL_PROJECTION); //View as projection
        glLoadIdentity();
        glOrtho(0, width, 0, height, 0, 1); //Set coordinate system as (0, screen width) as x axis range and (0, screen height) as y axis range
        glMatrixMode(GL_MODELVIEW); // Switch back to default view
        glLoadIdentity();
        return 0;
 
    }
 
   int go(vector<Point> points){
        int check= GUIStart();
        while (!glfwWindowShouldClose(window)){
            glClear(GL_COLOR_BUFFER_BIT);//Clear window
            glEnableClientState(GL_VERTEX_ARRAY); //Using a vertex array
            for (auto i=points.begin();i!= points.end(); i++){
                Point &p= *i;
                plotPixel(p);
            }
            glDisableClientState(GL_VERTEX_ARRAY);
            glfwSwapBuffers(window);
            glfwPollEvents(); //Poll events
        }
        glfwTerminate();
        return 0;
    }
};