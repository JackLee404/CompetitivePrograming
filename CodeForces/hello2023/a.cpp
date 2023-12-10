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
const int N = 1e5 + 10;

/*
	只能交换一次
	1. 存在LR那么通过交换一次一定可以, 若存在RL0次交换
*/

void solve() {
	int n, cntl = 0, cntr = 0; cin >> n;
	int can = -1;
	vector<char> a(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		if (i > 1 && a[i - 1] != a[i]) {
			if (a[i - 1] == 'L') can = i - 1;
			else can = 0;
		}
		if (a[i] == 'L') {
			cntl ++;
		} else if (a[i] == 'R') {
			cntr ++;
		}
	}
	if (!cntl || !cntr) puts("-1");
	else {
		cout << can << "\n";
	}
}

int main() {
	int _;
	cin >> _;
	while (_ --) {
		solve();
	}
}