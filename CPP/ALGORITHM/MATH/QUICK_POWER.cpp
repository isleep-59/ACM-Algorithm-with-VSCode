#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 2e5 + 10;

inline ll qpow(ll base, ll power, ll p) {
    ll ans = 1;
    base %= p;
    while(power) {
        if(power & 1)
            ans = ans * base % p;     
        base = base * base % p;
        power >>= 1;
    }
    return ans;
}

void solve(ll a, ll b, ll p) {
    int ans = qpow(a, b, p) % p;

    printf("%d^%d mod %d=%d\n", a, b, p, ans);
}

signed main() {
    std::ios::sync_with_stdio(false);

    ll a, b, p;
    while(cin >> a >> b >> p) {
        solve(a, b, p);
    }

    return 0;
}