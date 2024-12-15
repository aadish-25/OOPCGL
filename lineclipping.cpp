#include <graphics.h>
#include <iostream>
#include <cmath>
using namespace std;

static int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
static int xmin, ymin, xmax, ymax;

int getcode(int x, int y)
{
    int code = 0;
    if (y > ymax)
        code |= TOP;
    if (y < ymin)
        code |= BOTTOM;
    if (x < xmin)
        code |= LEFT;
    if (x > xmax)
        code |= RIGHT;
    return code;
}
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL); // Init window for Linux
    setcolor(WHITE);
    cout << "Enter top left and bottom right co-ordinates of window: ";
    cin >> xmin >> ymin >> xmax >> ymax;
    rectangle(xmin, ymin, xmax, ymax);

    int x1, y1, x2, y2;
    cout << "Enter the endpoints of the line: ";
    cin >> x1 >> y1 >> x2 >> y2;
    line(x1, y1, x2, y2);
    delay(5000);
    
    int outcode1 = getcode(x1, y1);
    int outcode2 = getcode(x2, y2);
    int accept = 0;

    while (1)
    {
        float m = (float)(y2 - y1) / (x2 - x1);
        if (outcode1 == 0 && outcode2 == 0)
        { // conditional
            accept = 1;
            break;
        }
        else if ((outcode1 & outcode2) != 0)
        { // bitwise and
            break;
        }
        else
        {
            int x, y;
            int temp;

            if (outcode1 != 0)
                temp = outcode1;
            else
                temp = outcode2; // temp = 8

            if (temp & TOP)
            {
                x = x1 + (ymax - y1) / m;
                y = ymax;
            }
            else if (temp & BOTTOM)
            {
                x = x1 + (ymin - y1) / m;
                y = ymin;
            }
            else if (temp & LEFT)
            {
                x = xmin;
                y = y1 + m * (xmin - x1);
            }
            else if (temp & RIGHT)
            {
                x = xmax;
                y = y1 + m * (xmax - x1);
            }
            if (temp == outcode1)
            {
                x1 = x;
                y1 = y;
                outcode1 = getcode(x1, y1);
            }
            else
            {
                x2 = x;
                y2 = y;
                outcode2 = getcode(x2, y2);
            }
        }
    }
    
    cleardevice();

    cout << "After clipping" << endl;
    rectangle(xmin, ymin, xmax, ymax);
    if (accept){
        cleardevice();      

        setcolor(BLUE);
        line(x1, y1, x2, y2);
    }

    delay(10000);
    closegraph();
    return 0;
}