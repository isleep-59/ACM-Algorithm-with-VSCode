#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
int st[N][25], _log2[N];

int query(int l, int r) {
    int k = _log2[r - l + 1];
    return max(st[l][k], st[r - (1 << k) + 1][k]);
    //return min(st[l][k], st[r - (1 << k) + 1][k]);
}

void init() {
    _log2[1] = 0;
    for(int i = 2; i <= n + 1; ++i)
        _log2[i] = _log2[i / 2] + 1;

    for(int j = 1; (1 << j) <= n; ++j) {
        for(int i = 1; i + (1 << j) - 1 <= n; ++i) {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
            //st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}

void solve() {
    for(int i = 1; i <= n; ++i)
        cin >> st[i][0];
    init();
    while(m--) {
        int l, r; cin >> l >> r;
        cout << query(l, r) << '\n';
    }
}

signed main() {
    // freopen("C:/Users/Luther/iCloudDrive/CODEs/VSCode/in.txt", "r", stdin);

    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(cin >> n >> m) {
        solve();
    }
    
    // fclose(stdin);
    return 0;
}