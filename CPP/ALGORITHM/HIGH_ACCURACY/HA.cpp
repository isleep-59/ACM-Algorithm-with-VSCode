//high accuracy algorithm
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>

#define ll long long int
#define scf scanf
#define prtf printf
#define mms(a) memset(a, 0, sizeof(a))

using namespace std;

int Compare(int a[100], int b[100])
{
    if(a[0] > b[0])
        return 1;
    if(a[0] < b[0]) 
        return -1;

    for (int i = 1; i <= a[0]; i++)
    {
        if(a[i] > b[i])
            return 1;
        if(a[i] < b[i])
            return -1;
    }

    return 0;
}

void Plus(int a[100], int b[100])
{
    int answer[101];
    memset(answer, 0, sizeof(answer));
    answer[0] = max(a[0], b[0]);

    for(int i = 1; i <= answer[0]; i++)
    {
        answer[i] += (a[i] + b[i]);
        answer[i + 1] += answer[i] / 10;
        answer[i] %= 10;
    }
    if (answer[answer[0]+1])
    {
        answer[0]++;
    }
    
    cout << "the sum is: ";
    for (int i = answer[0]; i >= 1; i--)
        cout << answer[i];
    cout << endl;
}

void Minus(int a[100], int b[100])
{
    int answer[101], sign = 0;
    memset(answer, 0, sizeof(answer));
    answer[0] = max(a[0], b[0]);

    if(Compare(a, b) == 0)
    {
        cout << 0 << endl;
        return;
    }

    if(Compare(a, b) > 0)
    {
        for (int i = 1; i <= answer[0]; i++)
        {
            if (a[i] < b[i])
            {
                answer[i + 1] -= 1;
                answer[i] = 10 + a[i] - b[i];
            }
            else
            {
                answer[i] += a[i] - b[i];
            }
        }
    }
}

int main()
{
    string number1, number2;
    int num1[100], num2[100];
    memset(num1, 0, sizeof(num1));
    memset(num2, 0, sizeof(num2));
    cin >> number1 >> number2;

    //note the length of the number
    num1[0] = number1.size();
    num2[0] = number2.size();
    //store the number in array in reversed order
    for (int i = 1; i <= num1[0]; i++)
    {
        num1[i] = number1[num1[0] - i] - '0';
    }
    for (int i = 1; i <= num2[0]; i++)
    {
        num2[i] = number2[num2[0] - i] - '0';
    }

    //Compare
    if(Compare(num1, num2) > 0)
        cout << "num1 > num2" << endl;
    else if(Compare(num1, num2) < 0)
        cout << "num1 < num2" << endl;
    else
        cout << "num1 == num2" << endl;

    //Plus
    Plus(num1, num2);

    //Minus
    //Minus(num1, num2);
}