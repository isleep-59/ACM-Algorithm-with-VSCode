#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;
const int maxn = 0x3f3f3f3f;
const int minn = -0x3f3f3f3f;

int n, m;
int Map[1000][1000];

void floyd() {
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                Map[i][j] = min(Map[i][j], Map[i][k] + Map[k][j]);
}

void solve() {
    for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++)
                Map[i][j] = (i == j ? 0 : maxn);
        
        for(int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            Map[u][v] = w;
        }

        floyd();

        int u, v;
        cin >> u >> v;
        cout << Map[u][v] << endl;
}

int main() {
    while(cin >> n >> m) {
        solve();
    }
}