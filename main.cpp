#include <stdio.h>
#include <math.h>
double distance(double a, double b, double c, double d)
{
    double x;
    x = sqrt((a - c) * (a - c) + (b - d) * (b - d));
    return x;
}
int main()
{
    double x1, y1, x2, y2, x3, y3;
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    double a, b, c, A, L;
    a = distance(x1, y1, x2, y2);
    b = distance(x1, y1, x3, y3);
    c = distance(x2, y2, x3, y3);
    L = a + b + c;
    if (a + b > c && a + c > b && b + c > a)
    {
        double p = L / 2.0;
        A = sqrt(p * (p - a) * (p - b) * (p - c));
        printf("L = %.2lf, A = %.2lf\n", L, A);
    }
    else
    {
        printf("Impossible");
    }
    return 0;
}