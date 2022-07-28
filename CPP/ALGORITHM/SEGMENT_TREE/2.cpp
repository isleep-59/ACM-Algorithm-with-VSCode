//区间修改，区间查询
#include <bits/stdc++.h>
#define ll long long
#define int ll
#define mms(a, b) memset(a, b, sizeof(a))
#define ls (rt << 1)
#define rs (rt << 1 | 1)
using namespace std;

const int INF = 0x3f3f3f3f;
const int N = 2e5 + 5;

int n, m, arr[N];
struct SegTree {
    int l, r;
    int sum, tag;
}Tree[N * 4];

inline void pushUp(int rt) {
    Tree[rt].sum = Tree[ls].sum + Tree[rs].sum;
}

inline void pushDown(int rt) {
    Tree[ls].tag += Tree[rt].tag;
    Tree[rs].tag += Tree[rt].tag;
    Tree[ls].sum += Tree[rt].tag * (Tree[ls].r - Tree[ls].l + 1);
    Tree[rs].sum += Tree[rt].tag * (Tree[rs].r - Tree[rs].l + 1);
    Tree[rt].tag = 0;
}

void build(int rt, int l, int r) {
    Tree[rt].l = l, Tree[rt].r = r;

    //叶子节点
    if (l == r) {
        Tree[rt].sum = arr[l];
        return;
    }

    int mid = l + r >> 1;
    build(ls, l, mid);		//构建左子树
    build(rs, mid + 1, r);	//构建右子树
    pushUp(rt);
}

void update(int rt, int l, int r, int k) {
    //如果管辖区间包含于更新区间，直接更新区间sum，并加上lazyTag
    if (l <= Tree[rt].l && Tree[rt].r <= r) {
        Tree[rt].sum += (Tree[rt].r - Tree[rt].l + 1) * k;
        Tree[rt].tag += k;
        return;
    }

    //如果懒标记需要下放，则先将当前节点的已存懒标记下放
    if (Tree[rt].tag)
        pushDown(rt); 

    //与左子树有交集
    if (l <= Tree[ls].r)
        update(ls, l, r, k);
    //与右子树有交集
    if (r >= Tree[rs].l)
        update(rs, l, r, k);

    pushUp(rt);
}

int query(int rt, int l, int r) {
    if (l <= Tree[rt].l && Tree[rt].r <= r)
        return Tree[rt].sum;

    pushDown(rt);

    int ret = 0;
    if (l <= Tree[ls].r)
        ret += query(ls, l, r);
    if (r >= Tree[rs].l)
        ret += query(rs, l, r);

    return ret;
}

void solve() {
    build(1, 1, n);
    while (m--) {
        int op; cin >> op;
        if (op == 1) {
            int l, r, k; cin >> l >> r >> k;
            update(1, l, r, k);
        }
        else if (op == 2) {
            int l, r; cin >> l >> r;
            cout << query(1, l, r) << '\n';
        }
    }
}

signed main() {
    //freopen("C:/Users/Luther/iCloudDrive/CODEs/VSCode/in.txt", "r", stdin);

    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i)
            cin >> arr[i];
        solve();
    }

    //fclose(stdin);
    return 0;
}