#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int maxn = 1e8 + 10;

int n;
bool isPrm[maxn];
int Prm[maxn];

int sieve() {
    int idx = 0;
    mms(isPrm, true);
    for (int i = 2; i <= n; i ++) {
        if(isPrm[i]) {
            Prm[idx++] = i;
        }

        for (int j = 0; j < idx && Prm[j] * i <= n; j++) {
            isPrm[i * Prm[j]] = false;
            if(i % Prm[j] == 0)
                break;
        }
    }

    return idx;
}

void solve() {
    int ans = sieve();

    cout << ans << '\n';
}

signed main() {
	std::ios::sync_with_stdio(false);

    while(cin >> n) {
        solve();
    }

    return 0;
}