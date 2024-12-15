#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    // Input for window coordinates
    int left, top, right, bottom;
    cout << "Enter the top-left coordinates (left, top) of the window: ";
    cin >> left >> top;
    cout << "Enter the bottom-right coordinates (right, bottom) of the window: ";
    cin >> right >> bottom;

    // Set the window size
    setviewport(left, top, right, bottom, 1);

    float x1, y1, x2, y2;
    cout << "Enter the first point (x1, y1): ";
    cin >> x1 >> y1;

    cout << "Enter the second point (x2, y2): ";
    cin >> x2 >> y2;

    // Line drawing algorithm
    float dx = x2 - x1;
    float dy = y2 - y1;
    float xin, yin;

    float len = (abs(dx) > abs(dy)) ? abs(dx) : abs(dy); // Length based on the larger difference
    xin = dx / len;
    yin = dy / len;

    float x = x1, y = y1;
    int i = 1;

    while (i <= len) {
        putpixel(round(x), round(y), GREEN);  // Draw the pixel
        x = x + xin;
        y = y + yin;
        i++;
    }

    delay(5000); // Wait for 5 seconds to view the output
    closegraph(); // Close the graphics window

    return 0;
}
