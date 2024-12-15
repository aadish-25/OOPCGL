#include <graphics.h>
#include <cmath>
#include <iostream>

using namespace std;

void kochCurve(int x1, int y1, int x2, int y2, int it){

    float angle = 60* (M_PI / 180);

    int x3 = (x2 + (2*x1))/3;
    int y3 = (y2 + (2*y1))/3;
    int x4 = ((2*x2) + x1)/3;
    int y4 = ((2*y2) + y1)/3;

    int x = x3 + cos(angle) * (x4-x3) + sin(angle) * (y4-y3);
    int y = y3 + cos(angle) * (y4-y3) - sin(angle) * (x4-x3);

    if (it > 0){
        kochCurve(x1, y1, x3, y3, it-1);
        kochCurve(x3, y3, x, y, it-1);
        kochCurve(x, y, x4, y4, it-1);
        kochCurve(x4, y4, x2, y2, it-1);
    }
    else{
        setcolor(2);
        line(x1, y1, x3, y3);
        line(x3, y3, x, y);
        line(x, y, x4, y4);
        line(x4, y4, x2, y2);
    }
}

int main(){
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int x1, x2;
    int y1, y2;
    int it;

    cout << "Enter the first point : " << endl;
    cin >> x1;
    cin >> y1;

    cout << "Enter the second point : " << endl;
    cin >> x2;
    cin >> y2;

    cout << "Enter the number of iterations : " << endl;
    cin >> it;

    kochCurve(x1, y1, x2, y2, it);

    delay(5000);
    closegraph();
    return 0;
}