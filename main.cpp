#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int sumY(int n)
{
    int sum = 0;
    for (int i = 1; i < n; i++)
    {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}

bool friendNum(int m, int n)
{
    return sumY(m) == sumY(n);
}

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);

    if (friendNum(M, N))
    {
        printf("True");
    }
    else
    {
        printf("False");
    }

    return 0;
}
