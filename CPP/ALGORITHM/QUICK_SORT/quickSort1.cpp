//取中间值为key做法
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>

#define MAX 100005

using namespace std;

int num[MAX];

void quickSort(int L, int R)
{
    int i = L, j = R, key;
    key = num[(L + R) / 2];

    do
    {
        while(num[i] < key) //to find a number greater than key
            i++;
        while(num[j] > key) //to find a number less than key
            j--;

        if(i <= j)
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
            i++;
            j--;
        }
    } while (i < j);

    if(L < j)
        quickSort(L, j);
    if(R > i)
        quickSort(i, R);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    quickSort(0, n-1);

    for (int i = 0; i < n; i++)
        cout << num[i] << (i != n - 1 ? ' ' : '\n');
}