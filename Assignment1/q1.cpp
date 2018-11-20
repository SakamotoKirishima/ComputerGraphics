#include <iostream>
#include <vector>
#include <GL/gl.h>
#include <file.hpp>
#include <GLFW/glfw3.h>
#include <cstdlib>
#include<cstdio>
#include<string>
 
using namespace std;
 
 
class Line{
    /**
    *This class is used to implement lines
    */
    private:
        Point start, end;
        int d,x,y,dx,dy;
        vector<Point> points_in_the_line;
 
        void getLineSlopeGreaterThanOrEqualTo1(){
            /**
            *Function to find all the points in the line when the slope is >=1
            */
            Point point(x,y);
            points_in_the_line.push_back(point);
            while (x<end.getx()){
                if (d<=0){
                    d+=2*dy;
                }
                else{
                    d+=(2*(dy-dx));
                    y++;
                }
                x++;
                Point point(x,y);
                points_in_the_line.push_back(point);
            }
        }
 
        void getLineSlopeLessThan1(){
            /**
            *Function to find all the points in the line when the slope is <1
            */
            Point point(x,y);
            points_in_the_line.push_back(point); //pushing the first point into the vector
            while (y<end.gety()){
                if (d<=0){
                    d+=2*dx;
                }
                else{
                    d+=(2*(dx-dy));
                    x++;
                }
                y++;
                Point point(x,y);
                points_in_the_line.push_back(point);
            }
        }
 
    public:
        Line(int start_x, int start_y, int end_x, int end_y): start(start_x,start_y), end(end_x, end_y){
            /** 
            *Line constructor
            **/
        }
 
        vector<Point> getLine(){
            /**
            *Function to get the points in the line
            **/
            if (end.getx()<start.getx()){
                swap(end,start);//ensure that start < end
            }
            dx= end.getx()-start.getx();
            dy= end.gety()- start.gety();
            d= (2*dx)- dy;
            x= start.getx();
            y= start.gety();
            if (dy==0 || dx/dy >=1){
                getLineSlopeGreaterThanOrEqualTo1();
            }
            else{
                getLineSlopeLessThan1();
            }
            return points_in_the_line;
        }  
};
 
 
 
void swap(Point& a, Point& b){
    /**
    *Swap two points
    **/
    Point temp = a;
    a = b;
    b = temp;
}
 
int main(int argc, char *argv[])
{
    /**
    *main()
    **/
    GUI gui(300, 300);
    if (argc != 5) return -1;
    int x0= atoi(argv[1]);
    int x1= atoi(argv[3]);
    int y0= atoi(argv[2]);
    int y1= atoi(argv[4]);
    Line line(x0,y0,x1,y1);
    vector<Point> points_to_be_drawn= line.getLine();
    int x= gui.go(points_to_be_drawn);
    cout << x;
    return 0;
}