#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int centx, centy, r;
    cout << "Enter the center and the radius of the circle : " << endl;
    cin >> centx;
    cin >> centy;
    cin >> r;

    int x = 0, y = r;
    int p = 3 - (2*r);

    do{
        
        putpixel(centx + x, centy - y, BLUE);
        putpixel(centx + y, centy - x, GREEN);

        putpixel(centx + y, centy + x, MAGENTA);
        putpixel(centx + x, centy + y, RED);

        putpixel(centx - x, centy + y, WHITE);
        putpixel(centx - y, centy + x, YELLOW);

        putpixel(centx - y, centy - x, LIGHTRED);
        putpixel(centx - x, centy - y, CYAN);
        

        if(p<0)
            p = p + (4*x) + 6;
        else{
            p = p + (4*(x-y)) + 10;
            y--;
        }
        x++;
    }while(x<y);

    


    delay(50000);
    closegraph();
    return 0;
}