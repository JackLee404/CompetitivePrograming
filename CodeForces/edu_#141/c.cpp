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
#define rc p<<1|1
using namespace std;
typedef long long LL;
typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
typedef priority_queue<int> B_HEAP; 
typedef pair<string, int> PSI;
typedef pair<int, int> PII;

const int N = 2600;

// ether b is the smallest or b is the greatest (= also)

void solve() {
	string t; cin >> t;
	int len = t.size();
	for(int l = 1; l < len - 1; l ++) {
		for(int r = 2; r < len; r ++) {
			string a = t.substr(0, l), b = t.substr(l, r - l), c = t.substr(r, len - r);
			if(b >= a && b >= c) {
				cout << a << " " << b << " " << c << "\n";
				return;
			}
			if(b <= a && b <= c) {
				cout << a << " " << b << " " << c << "\n";
				return;
			}
		}
	}
}

int main() {
	int _; cin >> _;
	while(_ --) {
		solve();
	}
}