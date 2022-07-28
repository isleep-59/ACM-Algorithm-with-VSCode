//取第一个值为key做法
#include <cstdio>
#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <algorithm>
using namespace std;

const int MAX = 1e5 + 5;

int num[MAX];

void quickSort(int L, int R)
{
    if (L > R)
        return;

    int i = L, j = R, key = num[L];

    while (i != j) //i haven't met with j yet
    {
        //from right to left
        while (num[j] >= key && j > i) //j to find a number less than key && j shouldn't go over i
            j--;
        while (num[i] <= key && i < j) //i to find a number greater than key && i shouldn't go over j
            i++;

        if (i < j)   //exchange their number while they haven't met
        {
            int temp = num[i];
            num[i] = num[j];
            num[j] = temp;
        }
    }

    //put the key into where it's expected to be
    num[L] = num[i];    //or = num[j], because only when i met with j can the exchange happen
    num[i] = key;

    quickSort(L, i - 1);
    quickSort(i + 1, R);
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> num[i];

    quickSort(0, n - 1);

    for (int i = 0; i < n; i++)
        cout << num[i] << (i != n - 1 ? ' ' : '\n');
}