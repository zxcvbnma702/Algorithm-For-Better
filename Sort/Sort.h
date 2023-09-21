#pragma once
#include <iostream>

#define maxsize 100

int a[maxsize] = {49, 38, 65, 97, 76, 13, 27, 49};

void insertDriect()
{
    int n = 8;

    for (int i = 0; i < n; i++)
    {
        int temp = a[i];

        int j;
        for (j = i - 1; j >= 0 && a[j] > temp; j--)
        {
            a[j + 1] = a[j];
        }

        a[j + 1] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        std::cout << a[i] << " ";
    }
    return;
}