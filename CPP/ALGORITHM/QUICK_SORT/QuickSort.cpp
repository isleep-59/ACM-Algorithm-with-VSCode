#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int num[N];

void QuickSort(int L, int R) {
    if(L >= R)
        return;
    int i = L, j = R;

    while(i < j) {
        while(j > i && num[j] >= num[L])
            j--;
        while(i < j && num[i] <= num[L])
            i++;
        swap(num[i], (i == j) ? num[L] : num[j]);
    }

    QuickSort(L, i - 1);
    QuickSort(j + 1, R);
}

void solve() {
    QuickSort(1, n);

    for(int i = 1; i <= n; ++i) {
        cout << num[i] << (i == n ? '\n' : ' ');
    }
}

signed main() {
    //freopen("C:\\Users\\Luther\\iCloudDrive\\CODEs\\VSCode\\in.txt", "r", stdin);

    std::ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    while(cin >> n) {
        for(int i = 1; i <= n; ++i) 
            cin >> num[i];
        solve();
    }

    //fclose(stdin);
    return 0;
}