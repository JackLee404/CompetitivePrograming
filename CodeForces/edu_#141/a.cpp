
#include <iostream>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
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
#define rc p<<1|1d;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;

const int N = 1e5 
using namespace st+ 10;

// f[i] != a[i]
// 5 3 5 5

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &x: a) {
		cin >> x;
	}
	sort(a.begin(), a.end(), greater<int>());
	bool ok = false;
	if(a[1] == a[0]) {
		for(int i = 2; i < n; i ++) {
			if(a[i] != a[0]) {
				ok = true;
				swap(a[1], a[i]);
			}
		}
	} else ok = true;
	if(!ok) {
		puts("NO");
		return;
	}
	puts("YES");
	for(int i = 0; i < n; i ++) {
		cout << a[i] << " \n"[i == n - 1];
	}
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}