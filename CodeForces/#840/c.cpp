#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define INF 0x3f3f3f3f
#define siz(x) (int)x.size()
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;
const int N = 1e5 + 10;

void solve() {
	long long n, mx = -1, mi = 0;
	cin >> n;
	vector<long long> a(n);
	rep (i, 0, siz(a) - 1) {
		cin >> a[i];
		if (a[i] >= mx) {
			mx = a[i];
			mi = i;
		}
	}
	if (siz(a) == 1) cout << a[0] << endl;
	else if (siz(a) == 2) cout << max(a[0] + a[1], 2 * abs(a[0] - a[1])) << endl;
	else if (siz(a) == 3) {
		if (a[0] == mx) mi = 0;
		else if (a[2] == mx) mi = 2;
		// cout << "mi:" << mi << endl;
		if (mi == 2 || mi == 0) {
			cout << 3 * mx << endl;
		} else {
			long long k1 = a[0] + a[1] + a[2];
			k1 = max(k1, (long long)3 * max(abs(a[2] - a[1]), abs(a[0] - a[1])));
			// k1 = max(k1, max(2 * abs(a[2] - a[1]) + a[0], 2 * abs(a[0] - a[1]) + a[2]));
			k1 = max(k1, 3 * a[0]);
			k1 = max(k1, 3 * a[2]);
			k1 = max(k1, 3 * abs(a[0] - a[2]));
			cout << k1 << endl;
		}
	} else {
		cout << (long long)n * mx << endl;
	}
}


int main() {
	IOS
	int _;
	cin >> _;
	while (_ --) {
		solve();	
	}
}