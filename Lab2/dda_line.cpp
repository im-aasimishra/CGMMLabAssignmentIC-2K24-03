/*
 * CGM Lab Assignment - 2
 * Question: Implement the Digital Differential Analyzer (DDA)
 * Line Drawing Algorithm to draw a straight line between
 * two given points using a graphics library.
 *
 * SUBMITTED BY : AASI MISHRA
 * Roll No      : IC-2K24-03
 */

#include <graphics.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int roundOff(float value)
{
    return (int)floor(value + 0.5f);
}

void ddaLine(int x1, int y1, int x2, int y2, int color)
{
    int dx = x2 - x1;
    int dy = y2 - y1;
    int steps;

    /* Calculate the number of steps */
    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    /* Handle identical starting and ending points */
    if (steps == 0)
    {
        putpixel(x1, y1, color);
        return;
    }

    /* Calculate increments */
    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = (float)x1;
    float y = (float)y1;

    /* Generate and plot intermediate points */
    for (int i = 0; i <= steps; i++)
    {
        putpixel(roundOff(x), roundOff(y), color);

        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    int x1, y1, x2, y2;
    char buf[100];

    /* Accept coordinates from the user */
    printf("=== DDA Line Drawing Algorithm ===\n");
    printf("Drawing area: x = 20 to 620, y = 110 to 430\n\n");

    printf("Enter starting point (x1 y1): ");
    scanf("%d %d", &x1, &y1);

    printf("Enter ending point (x2 y2): ");
    scanf("%d %d", &x2, &y2);

    /* Calculate differences and steps */
    int dx = x2 - x1;
    int dy = y2 - y1;

    int steps;

    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    /* Display calculated values */
    printf("\ndx = %d, dy = %d, steps = %d\n", dx, dy, steps);

    if (steps != 0)
    {
        printf("x_increment = %.3f, y_increment = %.3f\n",
               (float)dx / steps, (float)dy / steps);
    }
    else
    {
        printf("Both points are identical.\n");
    }

    /* Initialize graphics */
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char*)"");

    /* Display assignment heading */
    setcolor(WHITE);
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 2);
    outtextxy(140, 25, (char*)"CGM LAB ASSIGNMENT - 02");

    /* Display algorithm and student information */
    settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
    outtextxy(190, 55, (char*)"DDA Line Drawing Algorithm");

    outtextxy(140, 80,
              (char*)"Name: Aasi Mishra  |  Roll No: IC-2K24-03");

    /* Draw rectangular boundary */
    setcolor(RED);
    rectangle(20, 110, 620, 430);

    /* Draw line using DDA algorithm */
    ddaLine(x1, y1, x2, y2, WHITE);

    /* Mark starting and ending points */
    setcolor(YELLOW);
    circle(x1, y1, 3);
    circle(x2, y2, 3);

    /* Display coordinates */
    setcolor(WHITE);

    sprintf(buf, "P1 = (%d, %d)   P2 = (%d, %d)",
            x1, y1, x2, y2);

    outtextxy(30, 440, buf);

    /* Display calculated values */
    sprintf(buf, "dx = %d   dy = %d   steps = %d",
            dx, dy, steps);

    outtextxy(30, 455, buf);

    /* Wait for a key before closing graphics */
    getch();

    closegraph();

    return 0;
}
