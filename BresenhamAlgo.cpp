#include <iostream>
#include <graphics.h>
#include <cmath>
using namespace std;

void printCoord(int x, int y){
    cout<<"("<<x<<","<<y<<")";
}

void BresenhamAlgo(int x1, int y1, int x2, int y2, int P, int dx, int doubDy, int diffDoubDyDx){
    for(int i=1; i<=dx; i++){
        if(P<0){
            printCoord(++x1, y1);
            line((x1-1)*50, y1*50, x1*50, y1*50);
            P = P + doubDy;
        }
        else if(P>=0){
            printCoord(++x1, ++y1);
            line((x1-1)*50, (y1-1)*50, x1*50, y1*50);
            P = P + diffDoubDyDx;
        }
    }
}

int main(){
    int x1, y1, x2, y2;
    cout<<"Enter coordinates of the starting point : ";
    cin>>x1>>y1;
    cout<<"Enter coordinates of the ending point : ";
    cin>>x2>>y2;

    int dx, dy, doubDy, diffDoubDyDx;
    dx = abs(x2-x1);
    dy = abs(y2-y1);
    doubDy = 2*dy;
    diffDoubDyDx = doubDy - (2 * dx);

    int gd=DETECT, gm;
    initgraph(&gd, &gm, (char*)"");
    printCoord(x1, y1);
    putpixel(x1, y1, RED);
    line(x1*50, y1*50, x2*50, y2*50);
    
    int P = doubDy - dx;
    BresenhamAlgo(x1, y1, x2, y2, P, dx,  doubDy, diffDoubDyDx);

    getch();
    closegraph();

    return 0;
}