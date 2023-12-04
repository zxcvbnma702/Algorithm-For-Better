#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

bool IsTrue(char *str, double num)
{
    int i = 0;
    double sum = 0.0;
    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum = sum * 10.0 + str[i] - '0';
        }
        else if (str[i] == '.')
        {
            i++;
            break;
        }
        else
        {
            return false;
        }
        i++;
    }

    double mm = 0.1;

    while (str[i] != '\0')
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            sum += (str[i] - '0') * mm;
            mm = mm * 0.1;
        }
        else
        {
            return false;
        }
        i++;
    }
    printf("%lf", sum);
    return sum >= num;
}

int main()
{
    double a = 123;
    int t = IsTrue("123.789", a);
    printf("%d", t);
}