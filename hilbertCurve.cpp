#include <iostream>
#include <graphics.h>

using namespace std;

void move(int dir, int h, int &x, int &y)
{
    if (dir == 1)
        y = y - h;
    if (dir == 2)
        x = x + h;
    if (dir == 3)
        y = y + h;
    if (dir == 4)
        x = x - h;
    lineto(x, y);
}

// void hilbert(int r, int d, int l, int u, int n, int h, int &x, int &y)
void hilbert(int d, int r, int u, int l, int n, int h, int &x, int &y)
{
    if (n > 0)
    {
        n--;
        // hilbert(d, r, u, l, n, h, x, y);
        // move(r, h, x, y);
        // hilbert(r, d, l, u, n, h, x, y);
        // move(d, h, x, y);
        // hilbert(r, d, l, u, n, h, x, y);
        // move(l, h, x, y);
        // hilbert(u, l, d, r, n, h, x, y);

        hilbert(r,d,l,u, n, h, x, y);
        move(d, h, x, y);
        hilbert(d,r,u,l, n, h, x, y);
        move(r, h, x, y);
        hilbert(d,r,u,l, n, h, x, y);
        move(u, h, x, y);
        hilbert(l,u,r,d, n, h, x, y);       
    }
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int n, x, y;
    int u = 1, r = 2, d = 3, l = 4; // direction values
    int h = 20;                     // size of lines
    int x0 = 100, y0 = 100;         // starting point of the curve

    cout << "Number of iterations for Hilbert\'s curve : ";
    cin >> n;
    x = x0;
    y = y0;

    moveto(x, y);

    // hilbert(r, d, l, u, n, h, x, y);       // ] SHAPE   
    hilbert(d,r,u,l, n, h, x, y);             // U SHAPE
 
    delay(10000);
    closegraph();
    return 0;
}