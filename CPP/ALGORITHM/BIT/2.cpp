//区间修改，单点查询
#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n, m;
int num[N], d[N], arr[N];

int lowbit(int x) {
    return x & (-x);
}

void update(int x, int k) {
    d[x] += k;
    while (x <= n) {
        arr[x] += k;
        x += lowbit(x);
    }
}

int query(int x) {
    int sum = 0;
    while (x > 0) {
        sum += arr[x];
        x -= lowbit(x);
    }
    return sum;
}

void solve() {
    for (int i = 1; i <= n; ++i) 
        cin >> num[i];
    for (int i = 1; i <= n; ++i)
        update(i, num[i] - num[i - 1]);

    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, k; cin >> l >> r >> k;
            update(l, k);
            update(r + 1, -k);
        }
        else if (op == 2) {
            int x; cin >> x;
            cout << query(x) << '\n';
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