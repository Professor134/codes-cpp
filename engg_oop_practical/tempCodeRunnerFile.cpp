#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>

void fill(int x,int y,int n_c,int o_c){
    if(getpixel(x,y) == o_c){
        putpixel(x,y,n_c);
        delay(1);
        fill(x+1,y,n_c,o_c);
        delay(1);
        fill(x-1,y,n_c,o_c);
        delay(1);
        fill(x,y-1,n_c,o_c);
        delay(1);
        fill(x,y+1,n_c,o_c);
    }
}

void main(){
    int gd = DETECT , gm;
    initgraph(&gd,&gm,NULL);
    line(100,100,50,400);
    line(100,100,150,400);
    line(50,400,100,200);
    line(150,400,100,200);
    

    fill(100,150,WHITE,BLACK);
    getch();
    closegraph();
}