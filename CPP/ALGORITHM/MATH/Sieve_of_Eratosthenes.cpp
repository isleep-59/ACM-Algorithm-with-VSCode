#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e8 + 10;

int n;
bool isPrm[maxn];

void sieve() {
    mms(isPrm, true);
    isPrm[0] = isPrm[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if(isPrm[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrm[j] = false;
            }
        }
    }
}

void solve() {
    sieve();

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if(isPrm[i])
            ans++;
    }

    cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);

    while(cin >> n) {
        solve();
    }

    return 0;
}