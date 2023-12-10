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
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;
const int N = 1e5 + 10;


LL f(LL n, LL p) {
	if (n == 0) return 0;
	n /= p;
	return n + f(n, p);
}

int main() {
	LL k;
	cin >> k;

	vector<PLL> v1;
	LL x = k;

	for (LL i = 2; i * i <= x; i ++) {
		if (x % i) continue;
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt ++;
		}
		v1.push_back({i, cnt});
	}

	if (x != 1) v1.push_back({x, 1});
	
	LL r1 = k, l1 = 0;

	while (l1 < r1) {
		LL mid = l1 + r1 >> 1;	
		bool ok = true;	
		for (auto x: v1) {
			if (f(mid, x.f) < x.s) ok = false;	
		}
		if (ok) r1 = mid;
		else l1 = mid + 1;
	}

	cout << l1 << endl;
}