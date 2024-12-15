// CIRCLE TRIANGLE CIRCLE

#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void drawCircle(int cx, int cy, int r){
    int x = 0, y = r;
    int p = 3-(2*r);

    do{
        putpixel(cx + x, cy - y, WHITE);
        putpixel(cx + y, cy - x, WHITE);
        putpixel(cx + y, cy + x, WHITE);
        putpixel(cx + x, cy + y, WHITE);
        putpixel(cx - x, cy + y, WHITE);
        putpixel(cx - y, cy + x, WHITE);
        putpixel(cx - y, cy - x, WHITE);
        putpixel(cx - x, cy - y, WHITE);

        if(p<0){
            p=p+(4*x)+10;
        }
        else{
            p=p+(4*(x-y))+10;
            y--;
        }
        x++;
    }while(x<y);

}

void drawLine(int x1, int y1, int x2, int y2){
    float dx = x2-x1;
    float dy = y2-y1;
    float len = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy);

    float xin = dx/len;
    float yin = dy/len;

    float x = x1;
    float y = y1;
    int i=1;

    while(i<=len){
        putpixel(round(x), round(y), WHITE);
        x = x + xin;
        y = y + yin;
        i++;
    }

}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x, y, r;
    cout << "Enter the center and radius of the circle : ";
    cin >> x >> y;
    cin >> r;

    drawCircle(x, y, r);

    int x1, y1, x2, y2, x3, y3;
    x1 = x;
    y1 = y-2*r;
    x2 = x-sqrt(3)*r;
    y2 = y + r;
    x3 = x+sqrt(3)*r;
    y3 = y + r;

    drawLine(x1, y1, x2, y2);
    drawLine(x2, y2,x3, y3);
    drawLine(x3, y3, x1, y1);
    

    int R= 2*r;
    drawCircle(x, y, R);

    delay(5000);
    closegraph();

    return 0;
}