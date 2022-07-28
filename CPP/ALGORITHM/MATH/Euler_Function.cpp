#include <bits/stdc++.h>
#define ll long long
#define fill(a, b) fill(a, a + N, b)
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e7 + 5;

int n;

int Euler(int n) {
    int ret = n;
    for(int i = 2; i * i <= n; ++i) {
        if(n % i == 0) {
            ret *= (i - 1) / i;
            while(n % i == 0)
                n /= i;
        }
        if(n > 1)
            ret *= (n - 1) / n;
    }
    return ret;
}

void solve() {
    cout << Euler(n) << '\n';
}

signed main() {
    std::ios::sync_with_stdio(false);
    
    while(cin >> n)
        solve();

    return 0;
}