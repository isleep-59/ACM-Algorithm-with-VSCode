#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 5e5 + 7;
const int MIN = -0x3f3f3f3f;

int n, m, start;
int dis[MAX];
bool vis[MAX];
struct Node {
    int v, w;
};
vector<Node> edge[MAX];

void addEdge(int u, int v, int w) {
    Node temp = { v, w };
    edge[u].push_back(temp);
}

void Dijkstra() {
    mms(vis, false);
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[start] = 0;

    for (int t = 0; t < n; t++) {
        int pos, minn = INF;
        // 找一个离start最近的点
        for (int i = 1; i <= n; i++) {
            if (!vis[i] && dis[i] < minn) {
                minn = dis[i];
                pos = i;
            }
        }

        vis[pos] = true;
        
        for (int i = 0; i < edge[pos].size(); i++) {
            int v = edge[pos][i].v, w = edge[pos][i].w;
            if (dis[pos] + w < dis[v]) {
                dis[v] = dis[pos] + w;
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