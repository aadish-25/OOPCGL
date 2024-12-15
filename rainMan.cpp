#include <iostream>
#include <graphics.h>
#include <cmath>

#define MaxWidth getmaxx()
#define MaxHeight getmaxy()
#define GroundY MaxHeight * 0.75

using namespace std;

void generateMan(int x, int legDis){

    // head
    circle(x, GroundY - 100, 20);

    //body
    line(x, GroundY-80, x, GroundY - 40);

    //legs
    line(x, GroundY - 40, x-legDis, GroundY);
    line(x, GroundY - 40, x+legDis, GroundY);

    //hands-elbow
    line(x, GroundY - 70, x+15, GroundY- 60);
    line(x, GroundY - 70, x+20, GroundY - 50);

    //hands-umbrella
    line(x+15, GroundY- 60, x+40, GroundY-70);
    line(x+20, GroundY - 50, x+40,GroundY-70);

    //umbrella stick
    line(x+40, GroundY-70, x+40, GroundY - 140);

    //umbrella
    pieslice(x+40, GroundY - 140, 0, 180, 60);

}

void generateRain(int x){
    for(int i = 0; i<555; i++){
        int rx = rand()%MaxWidth;
        int ry = rand()%GroundY-10;
        if(ry < GroundY - 150)
            line(rx, ry, rx, ry+5);
        else{
            if(rx > x+100 || rx < x-40){
                line(rx, ry, rx, ry+5);
            }
        }
            
    }
    
}

int main() {
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int legDistance = 0;
    int x = 0;

    while(!kbhit()){
        line(0, GroundY, MaxWidth, GroundY);
        legDistance = (legDistance+2)%20;
        generateMan(x, legDistance);
        generateRain(x);
        x = (x+2)%MaxWidth;

        delay(10);
        cleardevice();
    }

    delay(1000); 
    closegraph();

    return 0;
}
