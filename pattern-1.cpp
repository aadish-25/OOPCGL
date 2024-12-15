// RECTANGLE RHOMBUS CIRCLE

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2){
    float dx = x2-x1;
    float dy = y2-y1;

    float len = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);
    float xin = dx/len;
    float yin = dy/len;

    float x = x1;
    float y = y1;
    int i = 1;

    while(i<=len){
        putpixel(round(x), round(y), WHITE);
        x = x + xin;
        y = y + yin;
        i++;
    }

}

void drawCircle(int cenx, int ceny, int r){

    int p = 3 - (2*r);
    int x = 0, y = r;

    do{
        putpixel(cenx + x, ceny - y, BLUE);
        putpixel(cenx + y, ceny - x, BLUE);
        putpixel(cenx + y, ceny + x, BLUE);
        putpixel(cenx + x, ceny + y, BLUE);
        putpixel(cenx - x, ceny + y, BLUE);
        putpixel(cenx - y, ceny + x, BLUE);
        putpixel(cenx - y, ceny - x, BLUE);
        putpixel(cenx - x, ceny - y, BLUE);

        if(p<0)
            p = p + (4*x) + 6;
        else{
            p = p + (4*(x-y)) + 10;
            y--;
        }
        delay(10);
        x++;
    }while(x<=y);
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, y1, x2, y2;

    cout << "Enter the vertices of the diagonals of the rectangle (top-left then bottom right) : ";
    cin >> x1;
    cin >> y1;
    cin >> x2;
    cin >> y2;

    drawLine(x1, y1, x2, y1);
    drawLine(x2, y1, x2, y2);
    drawLine(x2, y2, x1, y2);
    drawLine(x1, y2, x1, y1);

    int X = (x1+x2)/2;
    int Y = (y1+y2)/2;

    drawLine(X, y1, x2, Y);
    drawLine(x2, Y, X, y2);
    drawLine(X, y2, x1, Y);
    drawLine(x1, Y, X, y1);

    int R = sqrt(pow(((x2-x1)/4), 2) + pow(((y2-y1)/4), 2));


    drawCircle(X, Y, R);

    delay(5000);
    closegraph();

    return 0;
}