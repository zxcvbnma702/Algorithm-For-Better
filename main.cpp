#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

typedef struct Point
{
    int x, int y;
} Point;

double dist(Point x, Point y)
{
    return sqrt((x.x - y.x) * (x.x - y.x) + (y.y - x.y) * (y.y - x.y));
}

double square(Point a, Point b, Point c)
{
    double e1 = dist(a, b);
    double e2 = dist(a, c);
    double e3 = dist(b, c);

    double s = (e1 + e2 + e2) / 2;

    return sqrt(s * (s - e1) * (s - e2) * (s - e3));
}

void maxTrangle(int ax[], int ay[], int n)
{
    Point ps[n];
    for (int i = 0; i < n; i++)
    {
        ps[i].x = ax[i];
        ps[i].y = ay[i];
    }

    double maxArea = 0;
    Point maxPoint[3];

    for (int i = 0; i < 98; i++)
    {
        for (int j = i + 1; j < 99; j++)
        {
            for (int k = j + 1; k < 100; k++)
            {
                int sq = square(ps[i], ps[j], ps[k]);
                if (sq > maxArea)
                {
                    maxArea = sq;
                    maxPoint[0] = ps[i];
                    maxPoint[1] = ps[j];
                    maxPoint[2] = ps[k];
                }
            }
        }
    }

    printf("%lf", maxArea);
    for (int i = 0; i < 3; i++)
    {
        printf("%d %d\n", maxPoint[i].x, maxPoint[i].y);
    }
}
