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

int k, n;
// 1 3 4 7 8
// 2 1 3 1 == 3
// 1 2 4 7 10
// 1 2 4 7

void solve() {
	bool check = false;
	cin >> k >> n;
	vector<int> ans;
	int cnt = 0, gap = 0;
	for (int i = 1; i <= n; i += gap) {
		gap ++;
		// cout << i << " ";
		// int nt;

		// if (i + gap >= n) {
		// 	nt = n - i;
		// } else {
		// 	nt = gap;
		// }

		if (k - cnt - 1 > n - i) {
			break;
		}
		
		ans.push_back(i);
		cnt ++;

		if (cnt == k) {
			break;
		}
	}

	// for (auto &v: ans) {
	// 	cout << v << " ";
	// }
	for (int i = 0; i < ans.size(); i ++) {
		cout << ans[i];
		if (i != (int) ans.size() - 1) cout << " ";
	}

	if (cnt < k) {
		cout << " ";
		int st = ans.back();
		while (cnt != k) {
			cnt ++, st ++;
			cout << st;
			if (cnt != k) {
				cout << " ";
			}
		}	
	}

	// } else {
	// 	if (check) {
	// 		ans.pop_back();
	// 		cnt --;
	// 	}
	// 	for (int i = 0; i < ans.size(); i ++) {
	// 		cout << ans[i];
	// 		cout << " ";
	// 	}
	// 	for (int i = ans[(int)ans.size() - 1];cnt < n; i++, cnt ++) {
	// 		cout << i;
	// 		if (cnt != n - 1) cout << " ";
	// 	}
	// }
	cout << "\n";
}


int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();
	}
}