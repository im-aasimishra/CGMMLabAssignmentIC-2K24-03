/*
 * CGM Lab Assignment - 2
 * Question: Write a C/C++ program using a graphics library or tool to implement
 *           the Digital Differential Analyzer (DDA) Line Drawing Algorithm to
 *           draw a straight line between two given points.
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

    if (abs(dx) >= abs(dy))
    {
        steps = abs(dx);
    }
    else
    {
        steps = abs(dy);
    }

    float xIncrement = (float)dx / steps;
    float yIncrement = (float)dy / steps;

    float x = x1;
    float y = y1;

    for (int i = 0; i <= steps; i++)
    {
        putpixel(roundOff(x), roundOff(y), color);

        x += xIncrement;
        y += yIncrement;
    }
}

int main()
{
    /* Define starting and ending coordinates */
    int x1 = 60, y1 = 150;
    int x2 = 580, y2 = 400;

    int gd = DETECT, gm;

    initgraph(&gd, &gm, (char*)"");

    /* Display student information */
    setcolor(WHITE);
    outtextxy(140, 30, (char*)"Name: Aasi Mishra | Roll No: IC-2K24-03");

    /* Draw line using DDA algorithm */
    ddaLine(x1, y1, x2, y2, WHITE);

    getch();
    closegraph();

    return 0;
}
