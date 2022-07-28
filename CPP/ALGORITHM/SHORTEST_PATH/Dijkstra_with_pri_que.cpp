#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

int n, m, start;
int dis[maxn];
struct Edge {
    int v, w;
};
struct Node {
    int u, dis;
    //priority_queue的默认顺序是从大到小
    //这里应当把dis最小的放在队首，所以重载'<'，使认为dis大的小
    friend bool operator<(const Node &a, const Node &b) {
        return a.dis > b.dis;
    }
};
vector<Edge> G[maxn];

inline void addEdge(int u, int v, int w) {
    G[u].push_back(Edge{ v, w });
}

void Dijkstra() {
    bool vis[maxn];
    for (int i = 1; i <= n; i++) {
        dis[i] = inf;
        vis[i] = false;
    }
    dis[start] = 0;
    priority_queue<Node> q;
    Node s = { start, 0 };
    q.push(s);

    while (!q.empty()) {
        Node temp = q.top();
        q.pop();
        int u = temp.u, d = temp.dis;

        if (vis[u])
            continue;
        else
            vis[u] = true;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v, w = G[u][i].w;
            if (d + w < dis[v]) {
                dis[v] = d + w;
                q.push(Node{ v, dis[v] });
            }
        }
    }
}

void solve() {
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        addEdge(u, v, w);
    }

    Dijkstra();

    for (int i = 1; i <= n; i++) {
        cout << dis[i] << (i == n ? '\n' : ' ');
    }
}

int main() {
    std::ios::sync_with_stdio(false);

    cin >> n >> m >> start;
    solve();

    return 0;
}