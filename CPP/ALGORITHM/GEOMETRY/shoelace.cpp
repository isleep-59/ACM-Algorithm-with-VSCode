#include <bits/stdc++.h>
#define ll long long
#define mms(a, b) memset(a, b, sizeof(a))

using namespace std;

const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
const double pi = acos(-1.0);
const int N = 100 + 5;

int n;
struct Node {
	int x, y;
}crd[N];

void solve() {
	for (int i = 1; i <= n; ++i)
		cin >> crd[i].x >> crd[i].y;
	crd[n + 1].x = crd[1].x, crd[n + 1].y = crd[0].y;
	double ans = 0;
	for (int i = 1; i <= n; ++i) {
		ans += crd[i].x * crd[i + 1].y - crd[i].y * crd[i + 1].x;
	}
	printf("%.1f\n", ans / 2.0);
}

void init() {
	
}

signed main() {
	//freopen("C:\\Users\\Luther\\iCloudDrive\\CODEs\\VSCode\\in.txt", "r", stdin);
	//freopen("C:\\Users\\Luther\\iCloudDrive\\CODEs\\VSCode\\out.txt", "w", stdout);

	//std::ios::sync_with_stdio(false);
	//cin.tie(NULL), cout.tie(NULL);

	while (cin >> n) {
		if (!n)
			break;
		solve();
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
}