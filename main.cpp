#include <stdio.h>
int main()
{
    int n, i;
    double sum = 0, x = 1;
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            sum += 1.0 / x;
        }
        else
        {
            sum -= 1.0 / x;
        }
        x += 3;
    }
    
    printf("sum = %.3lf", sum);
    return 0;
}