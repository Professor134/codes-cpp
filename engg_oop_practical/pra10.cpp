
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>
#include <stdlib.h>

#define MAX 20

int x[MAX], y[MAX];
int n;

// Draw polygon using entered coordinates
void drawPolygon()
{
    int i;

    setcolor(WHITE);

    for (i = 0; i < n - 1; i++)
    {
        line(x[i], y[i], x[i + 1], y[i + 1]);
        delay(300);
    }

    line(x[n - 1], y[n - 1], x[0], y[0]);
    delay(500);
}

// Scan Line Polygon Filling Algorithm
void scanLineFill(int fillColor)
{
    int i, j, k;
    int temp;
    int ymin, ymax;
    int scanY;
    int intersections[MAX];

    ymin = y[0];
    ymax = y[0];

    // Find minimum and maximum Y coordinates
    for (i = 1; i < n; i++)
    {
        if (y[i] < ymin)
            ymin = y[i];

        if (y[i] > ymax)
            ymax = y[i];
    }

    setcolor(fillColor);

    // Process each horizontal scan line
    for (scanY = ymin; scanY <= ymax; scanY++)
    {
        k = 0;

        for (i = 0, j = n - 1; i < n; j = i++)
        {
            if ((y[i] <= scanY && y[j] > scanY) ||
                (y[j] <= scanY && y[i] > scanY))
            {
                intersections[k] =
                    x[i] + (scanY - y[i]) *
                    (x[j] - x[i]) / (y[j] - y[i]);

                k++;
            }
        }

        // Sort intersection points
        for (i = 0; i < k - 1; i++)
        {
            for (j = i + 1; j < k; j++)
            {
                if (intersections[i] > intersections[j])
                {
                    temp = intersections[i];
                    intersections[i] = intersections[j];
                    intersections[j] = temp;
                }
            }
        }

        // Fill between pairs of intersections
        for (i = 0; i < k - 1; i += 2)
        {
            line(intersections[i], scanY,
                 intersections[i + 1], scanY);

            delay(5);
        }
    }

    drawPolygon(); // Redraw the polygon boundary after filling
}

void main()
{
    int gd = DETECT, gm;
    int i, choice, fillColor;

    clrscr();

    cout << "SCAN LINE POLYGON FILLING ALGORITHM\n";
    cout << "===================================\n";

    cout << "Enter number of vertices (3 to "
         << MAX << "): ";
    cin >> n;

    if (n < 3 || n > MAX)
    {
        cout << "Invalid number of vertices!";
        getch();
        return;
    }

    cout << "\nEnter vertex coordinates (X Y):\n";

    for (i = 0; i < n; i++)
    {
        cout << "Vertex " << i + 1 << ": ";
        cin >> x[i] >> y[i];
    }

    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw polygon automatically
    drawPolygon();

    // Colour selection menu
    cout << "\nSelect fill colour:\n";
    cout << "1. Red\n";
    cout << "2. Green\n";
    cout << "3. Blue\n";
    cout << "4. Yellow\n";
    cout << "5. Cyan\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
        case 1:
            fillColor = RED;
            break;

        case 2:
            fillColor = GREEN;
            break;

        case 3:
            fillColor = BLUE;
            break;

        case 4:
            fillColor = YELLOW;
            break;

        case 5:
            fillColor = CYAN;
            break;

        default:
            cout << "\nInvalid choice! Using GREEN.";
            fillColor = GREEN;
            delay(1000);
    }

    scanLineFill(fillColor);

    setcolor(WHITE);
    outtextxy(10, 10, "Scan Line Polygon Filling");

    getch();
    closegraph();
}
