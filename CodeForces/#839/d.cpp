#include <iostream>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
#include <unordered_set>
#include <unordered_map>
#define INF 0x3f3f3f3f
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
	long long n, ml = 0, mr = 1e9;
	cin >> n;
	vector<long long> a(n);
	rep (i, 0, n - 1) {
		cin >> a[i];
		if (i >= 1) {
			if (a[i] > a[i - 1]) {
				mr = min(mr, (a[i] + a[i - 1]) / 2);
			} else if (a[i] < a[i - 1]) {
				ml = max(ml, (a[i] + a[i - 1] + 1) / 2);
			}
		}
	}
	if (ml <= mr) {
		cout << mr << endl;
	} else {
		cout << -1 << endl;
	}
}

int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();
	}
}