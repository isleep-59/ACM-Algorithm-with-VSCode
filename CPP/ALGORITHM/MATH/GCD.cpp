#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    return b ? gcd(b, a % b) : a;
}

void solve() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << '\n';
}

signed main() {
    freopen("in.txt", "r", stdin);
    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    fclose(stdin);
    return 0;
}