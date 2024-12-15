#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
static int xmin, xmax, ymin, ymax;

int getOutcodes(int x, int y){
    int code = 0;
    if(x < xmin)
        code = code | LEFT;
    if(x > xmax)
        code = code | RIGHT;
    if(y < ymin)
        code = code | BOTTOM;
    if(y > ymax)
        code = code | TOP;

    return code;
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    
    cout << "Enter the xmin ymin and xmax ymax for the window : " << endl;
    cin >> xmin >> ymin >> xmax >> ymax;


    int x1, y1, x2, y2;
    cout << "Enter the co-ordinates for line : " << endl;
    cin >> x1 >> y1;
    cin >> x2 >> y2;


    cout << "Initial : " << endl;
    rectangle(xmin, ymin, xmax, ymax);
    line(x1, y1, x2, y2);

    delay(5000);

    int outcode1 = getOutcodes(x1, y1);
    int outcode2 = getOutcodes(x2, y2);

    int accept = 0;
    
    while(1){
        float m = (float)(y2 - y1) / (x2 - x1);

        if(outcode1 == 0 && outcode2 == 0){
            cout << "Clipping not required" << endl;
            accept = 1;
            break;
        }
       

        else if((outcode1 & outcode2)!=0){
            cout << "Completely outside" << endl;
            break;
        }
        
        else{
            //Partially inside
            int x, y;
            int temp;

            if(outcode1 != 0)
                temp = outcode1;
            else
                temp = outcode2;

            if(temp & TOP){
                y = ymax;
                x = (m*x1 - y1 + ymax)/m;
            }
            if(temp & BOTTOM){
                y = ymin;
                x = (m*x1 - y1 + ymin)/m;
            }
            if(temp & LEFT){
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            if(temp & RIGHT){
                x = xmax;
                y = y1 + m * (xmax - x1);
            }

            // clip temp and (x,y)
            if(temp == outcode1){
                x1 = x;
                y1 = y;
                outcode1 = getOutcodes(x1, y1);
            }
            if(temp == outcode2){
                x2 = x;
                y2 = y;
                outcode2 = getOutcodes(x2, y2);
            }
        }
    }

    cleardevice();

    cout << "After clipping" << endl;
    rectangle(xmin, ymin, xmax, ymax);
    if (accept){      

        setcolor(BLUE);
        line(x1, y1, x2, y2);
    }

    delay(5000);
    closegraph();
}