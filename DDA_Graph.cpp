#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void printCoord(int x, int y){
    cout<<"("<<x<<","<<y<<")";
}

int DDA(double x, double y, float xInc, float yInc, double steps){
    for(int i=1; i<=steps; i++){
        x += xInc;
        y += yInc;
        printCoord(round(x), round(y));
        line(round(x-xInc)*50, round(y-yInc)*50, round(x)*50, round(y)*50);
    }
}

int main(){
    double x1, y1, x2, y2;
    cout<<"Enter coordinates of starting point : ";
    cin>>x1>>y1;
    cout<<"Enter coordinates of ending point : ";
    cin>>x2>>y2;
    double dx = x2 - x1, dy = y2 - y1;
    double steps = (dx>=dy ? dx : dy);
    float xInc = dx/steps, yInc = dy/steps;
    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    line(x1*50, y1*50, x2*50, y2*50);
    DDA(x1, y1, xInc, yInc, steps);
    getch();
    closegraph();
    return 0;
}