#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;
const int INF = 2e31 - 1;
const int MIN = -0x3f3f3f3f;

int n, m, start;
int dis[200005];
struct Edge {
    int v, w;
};
vector<Edge> G[200005];

inline void addEdge(int u, int v, int w) {
    Edge temp = { v, w };
    G[u].push_back(temp);
}

void SPFA() {
    queue<int> q;
    bool vis[200005];
    for (int i = 1; i <= n; i++) {
        dis[i] = INF;
        vis[i] = false;
    }
    dis[start] = 0;
    vis[start] = true;
    q.push(start);

    while(!q.empty()) {
        int u = q.front();
        q.pop();
        vis[u] = false;

        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i].v, w = G[u][i].w;
            if(dis[u] + w < dis[v]) {
                dis[v] = dis[u] + w;
                if(!vis[v]) {
                    vis[v] = true;
                    q.push(v);
                }
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

    SPFA();

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