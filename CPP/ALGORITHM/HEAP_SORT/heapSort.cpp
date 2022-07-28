#include <bits/stdc++.h>
#define mms(a, b) memeset(a, b, sizeof(a))
using namespace std;

void heapBuilt(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        int child = i;
        int father = (child - 1) / 2;

        while (v[child] > v[father])    //升序排列
        {
            swap(v[child], v[father]);
            child = father;
            father = (child - 1) / 2;
        }
    }
}

void heapSort(vector<int> &v)
{
    heapBuilt(v, v.size());

    for (int i = 0; i < v.size(); i++)
    {
        swap(v.front(), v[v.size() - i - 1]);
        heapBuilt(v, v.size() - i - 1);
    }
}

void heapDisplay(vector<int> &v)
{
    for (int i = 0; i < v.size(); i++)
        printf("%d%c", v[i], (i == v.size() - 1 ? '\n' : ' '));
}

int main()
{
    int temp;
    vector<int> heap;
    while (cin >> temp)
        heap.push_back(temp);

    heapSort(heap);

    cout << "After Sort:" << endl;
    heapDisplay(heap);

    return 0;
}