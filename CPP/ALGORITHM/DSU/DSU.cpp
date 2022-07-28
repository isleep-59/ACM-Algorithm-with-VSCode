#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

int pre[10001];

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

void merge(int a, int b)
{
    if (find(a) != find(b))
        pre[find(b)] = find(a);
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        pre[i] = i;

    while (m--)
    {
        int x, y, z;
        cin >> z >> x >> y;

        if (z == 1)
            merge(x, y);
        else if (z == 2)
        {
            if (find(x) == find(y))
                cout << "Y" << endl;
            else
                cout << "N" << endl;
        }
    }
}