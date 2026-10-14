
#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265

// Draw triangle using three vertices
void drawObject(float p[3][3], int color)
{
    int i;

    setcolor(color);

    for (i = 0; i < 3; i++)
    {
        line((int)(p[i][0] + 0.5),
             (int)(p[i][1] + 0.5),
             (int)(p[(i + 1) % 3][0] + 0.5),
             (int)(p[(i + 1) % 3][1] + 0.5));
    }
}

// Correct matrix multiplication
// Each row of p represents one vertex
void transform(float p[3][3], float t[3][3],
               float result[3][3])
{
    int i, j, k;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            result[i][j] = 0;

            for (k = 0; k < 3; k++)
            {
                result[i][j] +=
                    t[j][k] * p[i][k];
            }
        }
    }
}

int main()
{
    int gd = DETECT, gm;
    int choice, subChoice, i;
    float angle, rad;
    float tx, ty, sx, sy, shx, shy;
    float cx, cy, temp;

    float p[3][3], original[3][3];
    float t[3][3], result[3][3];

    clrscr();

    // Original triangle vertices
    p[0][0] = 200;
    p[0][1] = 150;
    p[0][2] = 1;

    p[1][0] = 300;
    p[1][1] = 150;
    p[1][2] = 1;

    p[2][0] = 250;
    p[2][1] = 250;
    p[2][2] = 1;

    // Save original triangle
    for (i = 0; i < 3; i++)
    {
        original[i][0] = p[i][0];
        original[i][1] = p[i][1];
        original[i][2] = p[i][2];
    }

    // Calculate triangle centroid
    cx = (p[0][0] + p[1][0] + p[2][0]) / 3.0;
    cy = (p[0][1] + p[1][1] + p[2][1]) / 3.0;

    cout << "2D GEOMETRIC TRANSFORMATIONS\n";
    cout << "\n1. Translation";
    cout << "\n2. Scaling";
    cout << "\n3. Rotation";
    cout << "\n4. Reflection";
    cout << "\n5. Shearing";
    cout << "\nEnter your choice: ";
    cin >> choice;

    // Initialize identity matrix
    for (i = 0; i < 3; i++)
    {
        t[i][0] = 0;
        t[i][1] = 0;
        t[i][2] = 0;
    }

    t[0][0] = 1;
    t[1][1] = 1;
    t[2][2] = 1;

    switch (choice)
    {
        case 1:
            cout << "Enter tx and ty: ";
            cin >> tx >> ty;

            t[0][2] = tx;
            t[1][2] = ty;
            break;

        case 2:
            cout << "Enter sx and sy: ";
            cin >> sx >> sy;

            // Scale around the triangle center
            t[0][0] = sx;
            t[1][1] = sy;

            t[0][2] = cx * (1 - sx);
            t[1][2] = cy * (1 - sy);
            break;

        case 3:
            cout << "Enter angle in degrees: ";
            cin >> angle;

            rad = angle * PI / 180.0;

            // Rotation around the triangle center
            t[0][0] = cos(rad);
            t[0][1] = -sin(rad);

            t[1][0] = sin(rad);
            t[1][1] = cos(rad);

            t[0][2] = cx
                    - cos(rad) * cx
                    + sin(rad) * cy;

            t[1][2] = cy
                    - sin(rad) * cx
                    - cos(rad) * cy;
            break;

        case 4:
            cout << "\n1. Reflection about horizontal axis";
            cout << "\n2. Reflection about vertical axis";
            cout << "\n3. Reflection about center";
            cout << "\nEnter choice: ";
            cin >> subChoice;

            if (subChoice == 1)
            {
                // Horizontal axis through center
                t[1][1] = -1;
                t[1][2] = 2 * cy;
            }
            else if (subChoice == 2)
            {
                // Vertical axis through center
                t[0][0] = -1;
                t[0][2] = 2 * cx;
            }
            else if (subChoice == 3)
            {
                // Reflection through center
                t[0][0] = -1;
                t[1][1] = -1;

                t[0][2] = 2 * cx;
                t[1][2] = 2 * cy;
            }
            else
            {
                cout << "Invalid reflection choice!";
                getch();
                return 0;
            }
            break;

        case 5:
            cout << "Enter shx and shy: ";
            cin >> shx >> shy;

            // Shear around the triangle center
            t[0][1] = shx;
            t[1][0] = shy;

            t[0][2] = -shx * cy;
            t[1][2] = -shy * cx;
            break;

        default:
            cout << "Invalid choice!";
            getch();
            return 0;
    }

    // Apply transformation to original vertices
    transform(original, t, result);

    // Initialize graphics
    initgraph(&gd, &gm, "C:\\TC\\BGI");

    // Draw original triangle in white
    drawObject(original, WHITE);

    // Draw transformed triangle in green
    drawObject(result, GREEN);

    // Display labels
    setcolor(WHITE);
    outtextxy(10, 10, "WHITE: Original Triangle");

    setcolor(GREEN);
    outtextxy(10, 25, "GREEN: Transformed Triangle");

    getch();
    closegraph();

    return 0;
}