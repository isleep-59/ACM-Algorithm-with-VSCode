#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
using namespace std;

int a, b;

int ex_gcd(int a, int b, int &x, int &y) {
    if(b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int g = ex_gcd(b, a % b, x, y);
    int tmp = x;
    x = y;
    y = tmp - (a / b) * y;
    return g;
}

void solve() {
    int x, y;
    cout << ex_gcd(a, b, x, y) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    // cin.tie(NULL), cout.tie(NULL);
    while(cin >> a >> b) {
        solve();
    }
}