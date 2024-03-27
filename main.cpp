#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <memory.h>

#include <iostream>


int main()
{
    int a = 1, b =2;
    int c = (a+b)/2;
    printf("%d", c);
}

void quick_sort(int a[], int left, int right)
{
    if(left >= right) return ;


    int i = left-1, j = right+1, x = a[left+ right >> 1];

    while (i<j)
    {
        do i++; while (a[i] < x);
        do j--; while (a[j] > x);
        if(i < j) swap(a[i][j])
    }

    quick_sort(a, left, j), quick_sort(a, j+1, right);
    
    
}
