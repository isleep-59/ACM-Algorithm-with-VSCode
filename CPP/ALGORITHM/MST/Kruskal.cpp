#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int maxn = 2e5 + 7;
int pre[maxn];
int n, m;

struct Node
{
    int u, v, w;
} edge[maxn];

bool cmp(Node a, Node b)
{
    return a.w < b.w;
}

int find(int x)
{
    return pre[x] == x ? x : pre[x] = find(pre[x]);
}

void merge(int a, int b)
{
    pre[find(a)] = find(b);
}

int kruskal()
{
    int ret = 0, cnt = 0;
    sort(edge, edge + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (find(edge[i].u) != find(edge[i].v)) //如果两个点不在同一个连通块
        {
            ret += edge[i].w;
            merge(edge[i].u, edge[i].v); //将两个点并到同一个连通块中
            cnt++;
        }
    }

    if (cnt != n - 1) //如果图不连通
        ret = -1;

    return ret;
}

int main()
{
    while (cin >> n >> m)
    {
        for (int i = 0; i < m; i++)
            cin >> edge[i].u >> edge[i].v >> edge[i].w;
        for (int i = 1; i <= n; i++) //初始化并查集
            pre[i] = i;

        int ans = kruskal();
        if (ans != -1)
            cout << ans << endl;
        else
            cout << "orz" << endl;
    }
}