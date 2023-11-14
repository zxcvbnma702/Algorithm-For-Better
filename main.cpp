#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>

int portition(int a[], int low, int high)
{
    int k = a[low];
    while (low < high)
    {
        while (low < high && a[high] > k)
        {
            high--;
        }

        a[low] = a[high];

        while (low < high && a[low] < k)
        {
            low++;
        }
        a[high] = a[low];
    }
    a[high] = k;
    return high;
}

void quick_Soct(int a[], int low, int high)
{
    if (low < high)
    {
        int mid = portition(a, low, high);
        quick_Soct(a, low, mid - 1);
        quick_Soct(a, mid + 1, high);
    }
}

int main()
{
    int a[10] = {19, 2, 39, 4, 59, 6, 79, 8, 9};
    quick_Soct(a, 0, 9);
    for (int i = 0; i < 10; i++)
    {
        std::cout << a[i] << " ";
    }
    printf("%d", a[10 - 2]);
}
