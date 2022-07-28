//单点修改，区间查询
#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 5e5 + 5;

int n, m, arr[N];
struct SegTree {
    int l, r;
    int sum;
}Tree[N * 4];

inline void pushup(int rt) {
    Tree[rt].sum = Tree[ls].sum + Tree[rs].sum;
}

void build(int rt, int l, int r) {
    Tree[rt].l = l, Tree[rt].r = r;

    if(l == r) {
        Tree[rt].sum = arr[l];
        return;
    }

    int mid = l + r >> 1;
    build(ls, l, mid);
    build(rs, mid + 1, r);
    pushup(rt);
}

void update(int rt, int pos, int k) {
    if(Tree[rt].l == Tree[rt].r) {
        Tree[rt].sum += k;
        return;
    }

    if(pos <= Tree[ls].r)
        update(ls, pos, k);
    else
        update(rs, pos, k);

    pushup(rt);
}

int query(int rt, int l, int r) {
    if(r < Tree[rt].l || l > Tree[rt].r)
        return 0;
    if(l <= Tree[rt].l && r >= Tree[rt].r)
        return Tree[rt].sum;
    
    int ret = 0;
    if(l <= Tree[ls].r)
        ret += query(ls, l, r);
    if(r >= Tree[rs].l)
        ret += query(rs, l, r);
    return ret;
}

void solve() {
    build(1, 1, n);
    while(m--) {
        int op; cin >> op;
        if(op == 1) {
            int pos, k;
            cin >> pos >> k;
            update(1, pos, k);
        }
        else {
            int x, y;
            cin >> x >> y;
            cout << query(1, x, y) << '\n';
        }
    }
}

signed main() {
    // freopen("C:/Users/Luther/iCloudDrive/CODEs/VSCode/in.txt", "r", stdin);
    // freopen("C:/Users/Luther/iCloudDrive/CODEs/VSCode/out.txt", "w", stdout);

    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(cin >> n >> m) {
        for(int i = 1; i <= n; ++i)
            cin >> arr[i];
        solve();
    }

    // fclose(stdin);
    // fclose(stdout);
    return 0;
}