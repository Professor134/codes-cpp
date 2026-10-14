
#include <graphics.h>
#include <iostream.h>// this not an error it requird beacuse grafics has version 3.0
#include <conio.h>
#include <math.h>
#include <stdlib.h>
#include <dos.h>
// DDA Line Drawing Algorithm
void DDA(int x1, int y1, int x2, int y2)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;
    int i;
    float xInc, yInc;
    float x, y;

    if (abs(dx) > abs(dy))
        steps = abs(dx);
    else
        steps = abs(dy);

    if (steps == 0)
    {
        putpixel(x1, y1, WHITE);
        return;
    }

    xInc = (float)dx / steps;
    yInc = (float)dy / steps;

    x = x1;
    y = y1;

    for (i = 0; i <= steps; i++)
    {
        putpixel((int)(x + 0.5), (int)(y + 0.5), RED);
        delay(5); // Optional delay for visualization   
        x = x + xInc;
        y = y + yInc;
    }
}

// Bresenham's Circle Drawing Algorithm
void BresenhamCircle(int xc, int yc, int r)
{
    int x = 0;
    int y = r;
    int p = 3 - 2 * r;

    while (x <= y)
    {
        putpixel(xc + x, yc + y, WHITE);
        putpixel(xc - x, yc + y, WHITE);
        putpixel(xc + x, yc - y, WHITE);
        putpixel(xc - x, yc - y, WHITE);

        putpixel(xc + y, yc + x, WHITE);
        putpixel(xc - y, yc + x, WHITE);
        putpixel(xc + y, yc - x, WHITE);
        putpixel(xc - y, yc - x, WHITE);
         delay(5); // Optional delay for visualization
        if (p < 0)
        {
            p = p + 4 * x + 6;
        }
        else
        {
            p = p + 4 * (x - y) + 10;
            y--;
        }

        x++;
    }
}

int main()
{
    int gd = DETECT, gm;

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Rectangle coordinates
    int left = 100;
    int top = 100;
    int right = 500;
    int bottom = 350;

    int cx = (left + right) / 2;
    int cy = (top + bottom) / 2;

    // Draw outer rectangle using DDA
    DDA(left, top, right, top);
    DDA(right, top, right, bottom);
    DDA(right, bottom, left, bottom);
    DDA(left, bottom, left, top);

    // Diamond vertices
    int topX = cx, topY = top;
    int rightX = right, rightY = cy;
    int bottomX = cx, bottomY = bottom;
    int leftX = left, leftY = cy;

    // Draw diamond using DDA
    DDA(topX, topY, rightX, rightY);
    DDA(rightX, rightY, bottomX, bottomY);
    DDA(bottomX, bottomY, leftX, leftY);
    DDA(leftX, leftY, topX, topY);

    // Draw circle using Bresenham's algorithm
    int radius = 105;
    BresenhamCircle(cx, cy, radius);

    getch();
    closegraph();

    return 0;
}