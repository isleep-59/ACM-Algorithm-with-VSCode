#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, m;
int num[N], tree[N];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int k) {
    num[x] += k;
    while(x <= n) {
        tree[x] = max(k, tree[x]);
        x += lowbit(x);
    }
}

int query(int l, int r) {
    int len = r - l + 1;
    if(len <= lowbit(r)) {
        return tree[r];
    }
}

void solve() {
    for(int i = 1; i <= n; ++i) {
        int tmp; cin >> tmp;
        update(i, tmp);
    }
}

signed main() {
    //freopen("C:/Users/Luther/iCloudDrive/CODEs/VSCode/in.txt", "r", stdin);

    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m) {
        solve();
    }

    //fclose(stdin);
    return 0;
}