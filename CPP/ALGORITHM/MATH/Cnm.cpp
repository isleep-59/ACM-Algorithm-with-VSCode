#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int N = 2e6 + 10;

int n, m;
ll fac[N], inv_fac[N];

inline ll qpow(ll base, ll power) {
    ll ret = 1;
    base %= mod;
    while (power) {
        if (power & 1)
            ret = (ret * base) % mod;
        base = (base * base) % mod;
        power >>= 1;
    }
    return ret;
}

void init() {
    fac[0] = 1;
    for (int i = 1; i <= N; i++) {
        fac[i] = (fac[i - 1] * i) % mod;
    }
    inv_fac[N] = qpow(fac[N], mod - 2);
    for (int i = N - 1; i >= 0; i--) {
        inv_fac[i] = (inv_fac[i + 1] * (i + 1)) % mod;
    }
}

ll C(int n, int m){
    return fac[n] * inv_fac[n - m] % mod * inv_fac[m] % mod;
}

void solve() {
    cout << C(n, m) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    init();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        solve();
    }

    return 0;
}