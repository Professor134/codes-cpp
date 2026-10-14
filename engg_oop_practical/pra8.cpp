#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

#define LEFT   1
#define RIGHT  2
#define BOTTOM 4
#define TOP    8

int xmin, ymin, xmax, ymax;

// Calculate region code for a point
int getCode(float x, float y)
{
    int code = 0;

    if (x < xmin)
        code = code | LEFT;
    else if (x > xmax)
        code = code | RIGHT;

    if (y < ymin)
        code = code | TOP;
    else if (y > ymax)
        code = code | BOTTOM;

    return code;
}

// Cohen-Sutherland line clipping
int clipLine(float *x1, float *y1,
             float *x2, float *y2)
{
    int code1, code2, codeOut;
    float x, y;

    code1 = getCode(*x1, *y1);
    code2 = getCode(*x2, *y2);

    while (1)
    {
        // Both endpoints are inside
        if ((code1 | code2) == 0)
            return 1;

        // Both endpoints are outside
        // in the same region
        if ((code1 & code2) != 0)
            return 0;

        // Select an endpoint outside the window
        if (code1 != 0)
            codeOut = code1;
        else
            codeOut = code2;

        // Find intersection with TOP edge
        if (codeOut & TOP)
        {
            if (*y2 == *y1)
                return 0;

            x = *x1 + (*x2 - *x1) *
                (ymin - *y1) / (*y2 - *y1);
            y = ymin;
        }
        // Find intersection with BOTTOM edge
        else if (codeOut & BOTTOM)
        {
            if (*y2 == *y1)
                return 0;

            x = *x1 + (*x2 - *x1) *
                (ymax - *y1) / (*y2 - *y1);
            y = ymax;
        }
        // Find intersection with RIGHT edge
        else if (codeOut & RIGHT)
        {
            if (*x2 == *x1)
                return 0;

            y = *y1 + (*y2 - *y1) *
                (xmax - *x1) / (*x2 - *x1);
            x = xmax;
        }
        // Find intersection with LEFT edge
        else
        {
            if (*x2 == *x1)
                return 0;

            y = *y1 + (*y2 - *y1) *
                (xmin - *x1) / (*x2 - *x1);
            x = xmin;
        }

        // Replace the outside endpoint
        if (codeOut == code1)
        {
            *x1 = x;
            *y1 = y;
            code1 = getCode(*x1, *y1);
        }
        else
        {
            *x2 = x;
            *y2 = y;
            code2 = getCode(*x2, *y2);
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    float x1, y1, x2, y2;
    float cx1, cy1, cx2, cy2;
    int result;

    clrscr();

    cout << "COHEN-SUTHERLAND LINE CLIPPING\n\n";

    cout << "Enter clipping window xmin ymin: ";
    cin >> xmin >> ymin;

    cout << "Enter clipping window xmax ymax: ";
    cin >> xmax >> ymax;

    if (xmin >= xmax || ymin >= ymax)
    {
        cout << "\nInvalid clipping window!";
        getch();
        return 0;
    }

    cout << "\nEnter line starting point x1 y1: ";
    cin >> x1 >> y1;

    cout << "Enter line ending point x2 y2: ";
    cin >> x2 >> y2;

    // Save original endpoints
    cx1 = x1;
    cy1 = y1;
    cx2 = x2;
    cy2 = y2;

    // Clip the line
    result = clipLine(&cx1, &cy1, &cx2, &cy2);

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw clipping window in white
    rectangle(xmin, ymin, xmax, ymax);

    // Draw original line in red
    setcolor(RED);
    line((int)x1, (int)y1, (int)x2, (int)y2);

    if (result == 1)
    {
        // Draw clipped line in green
        setcolor(GREEN);
        line((int)cx1, (int)cy1,
             (int)cx2, (int)cy2);

        if (cx1 == x1 && cy1 == y1 &&
            cx2 == x2 && cy2 == y2)
        {
            cout << "\nLine is completely visible.";
        }
        else
        {
            cout << "\nLine is partially visible.";
        }

        cout << "\nClipped endpoints: ";
        cout << "(" << cx1 << ", " << cy1 << ")";
        cout << " to ";
        cout << "(" << cx2 << ", " << cy2 << ")";
    }
    else
    {
        cout << "\nLine is completely invisible.";
    }

    cout << "\n\nRED = Original line";
    cout << "\nGREEN = Clipped line";
    cout << "\nPress any key to exit.";

    getch();
    closegraph();

    return 0;
}
