#include <iostream>
#include <graphics.h>
using namespace std;

void printCoord(int x, int y){
    cout<<"("<<x<<","<<y<<")";
}

void MidpntAlgo(int xk, int yk, int P, int xShift, int yShift, int scale){
    if(P<0){
        int xkn = xk + 1, ykn = yk;
        if(xkn < ykn){
            printCoord(xkn, ykn);
            printCoord(ykn, xkn);
            printCoord(xkn, -ykn);
            printCoord(ykn, -xkn);
            printCoord(-xkn, -ykn);
            printCoord(-ykn, -xkn);
            printCoord(-xkn, ykn);
            printCoord(-ykn, xkn);
            line((xk*scale) + xShift, (yk*scale) + yShift, (xkn*scale) + xShift, (ykn*scale) + yShift);
            line((yk*scale) + xShift, (xk*scale) + yShift, (ykn*scale) + xShift, (xkn*scale) + yShift);
            line((xk*scale) + xShift, -(yk*scale) + yShift, (xkn*scale) + xShift, -(ykn*scale) + yShift);
            line((yk*scale) + xShift, -(xk*scale) + yShift, (ykn*scale) + xShift, -(xkn*scale) + yShift);
            line(-(xk*scale) + xShift, (yk*scale) + yShift, -(xkn*scale) + xShift, (ykn*scale) + yShift);
            line(-(yk*scale) + xShift, (xk*scale) + yShift, -(ykn*scale) + xShift, (xkn*scale) + yShift);
            line(-(xk*scale) + xShift, -(yk*scale) + yShift, -(xkn*scale) + xShift, -(ykn*scale) + yShift);
            line(-(yk*scale) + xShift, -(xk*scale) + yShift, -(ykn*scale) + xShift, -(xkn*scale) + yShift);
            MidpntAlgo(xkn, ykn, P + (2 * xkn) + 3, xShift, yShift, scale);
        }
    }
    else if(P >= 0){
        int xkn = xk + 1, ykn = yk - 1;
        if(xkn < ykn){
            printCoord(xkn, ykn);
            printCoord(ykn, xkn);
            printCoord(xkn, -ykn);
            printCoord(ykn, -xkn);
            printCoord(-xkn, -ykn);
            printCoord(-ykn, -xkn);
            printCoord(-xkn, ykn);
            printCoord(-ykn, xkn);
            line((xk*scale) + xShift, (yk*scale) + yShift, (xkn*scale) + xShift, (ykn*scale) + yShift);
            line((yk*scale) + xShift, (xk*scale) + yShift, (ykn*scale) + xShift, (xkn*scale) + yShift);
            line((xk*scale) + xShift, -(yk*scale) + yShift, (xkn*scale) + xShift, -(ykn*scale) + yShift);
            line((yk*scale) + xShift, -(xk*scale) + yShift, (ykn*scale) + xShift, -(xkn*scale) + yShift);
            line(-(xk*scale) + xShift, (yk*scale) + yShift, -(xkn*scale) + xShift, (ykn*scale) + yShift);
            line(-(yk*scale) + xShift, (xk*scale) + yShift, -(ykn*scale) + xShift, (xkn*scale) + yShift);
            line(-(xk*scale) + xShift, -(yk*scale) + yShift, -(xkn*scale) + xShift, -(ykn*scale) + yShift);
            line(-(yk*scale) + xShift, -(xk*scale) + yShift, -(ykn*scale) + xShift, -(xkn*scale) + yShift);
            MidpntAlgo(xkn, ykn, P + (2 * xkn) - (2 * ykn) + 5, xShift, yShift, scale);
        }
    }
}

int main(){
    int r;
    int xShift = 960, yShift = 520, scale = 1;
    cout<<"Enter radius of the circle : ";
    cin>>r;
    int x = 0, y = r, P = (1-r);

    int gd = DETECT, gm;
    // initgraph(&gd, &gm, (char*)"");
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    initwindow(screenWidth, screenHeight, "Full Size BGI Window");

    cout<<"Points of the first octant of the circle : ";
    printCoord(x, y);
    MidpntAlgo(x, y, P, xShift, yShift, scale);

    getch();

    closegraph();

    return 0;
}