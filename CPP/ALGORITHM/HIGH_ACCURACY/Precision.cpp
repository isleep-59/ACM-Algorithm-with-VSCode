#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))
#define Equ(a, b) (fabs(a - b) < EPS)
#define Grt(a, b) (a - b > EPS)
#define Lss(a, b) (a - b < -EPS)
#define LssEqu(a, b) (a - b < EPS)
#define GrtEqu(a, b) (fabs(a - b) > -EPS)
using namespace std;

//EPS需根据所求小数点后精度改变
const double EPS = 1e-9;

double a, b;

inline int sgn(double a) {
    return a < -EPS ? -1 : a < EPS ? 0 : 1;
}

void solve() {
    double jdg = a - b;

    if(sgn(jdg) == 0 && Equ(a, b)) {
        cout << "a == b" << '\n';
    }
    else if(sgn(jdg) < 0 && Lss(a, b)) {
        cout << "a < b" << '\n';
    }
    else if(sgn(jdg) > 0 && Grt(a, b)) {
        cout << "a > b" << '\n';
    }
    else if(sgn(jdg) <= 0 && LssEqu(a, b)) {
        cout << "a <= b" << '\n';
    }
    else if(sgn(jdg) >= 0 && GrtEqu(a, b)) {
        cout << "a >= b" << '\n';
    }
    else {
        cout << "ERROR !" << '\n';
    }
}

signed main() {
    while(cin >> a >> b) {
        solve();
    }
}