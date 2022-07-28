//区间修改，区间查询
#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n, m;
int tree1[N], tree2[N], d[N], num[N];

inline int lowbit(int x) {
    return x & (-x);
}

inline void update(int x, int k) {
    d[x] += k;
    while(x <= n) {
        tree1[x] += k;
        tree2[x] += k * x;
        x += lowbit(x);
    }
}

inline int query(int x) {
    int sum = 0, tmp = x;
    while(x > 0) {
        sum += (tmp + 1) * tree1[x] - tree2[x];
        x -= lowbit(x);
    }
    return sum;
}

void solve() {
    for(int i = 1; i <= n; ++i) 
        cin >> num[i];
    for(int i = 1; i <= n; ++i) 
        update(i, num[i] - num[i - 1]);
    
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int l, r, k; cin >> l >> r >> k;
            update(l, k);
            update(r + 1, -k);
        }
        else if(op == 2) {
            int l, r; cin >> l >> r;
            int ans = query(r) - query(l - 1);
            cout << ans << '\n';
        }
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