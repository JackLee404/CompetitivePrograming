#include <iostream>
#include <vector>
#include <queue>
#define rep(i, j, n) for (int i = j; i <= n; i ++)
#define per(i, j, n) for (int i = j; i >= n; i --)
using namespace std;

/*
	设置一个堆，对kj于
	pre[m] - 2 * a[x]
*/

void clear(priority_queue<int> &h) {
	while (h.size()) h.pop();
}

void solve() {
	int n, m, cnt = 0; cin >> n >> m;
	vector<int> a(n + 1), pre(n + 1);
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
		pre[i] = pre[i - 1] + a[i];
	}
	priority_queue<int> h;
	int tag = 0;
	per (i, m - 1, 0) {
		while (h.size() && pre[i] < pre[m] + 2 * tag) {
			tag -= h.top(), h.pop();
			cnt ++;
		}
		if (a[i] > 0) h.push(a[i]);
	}
	priority_queue<int, vector<int>, greater<int>> h2;
	int tag2 = 0;
	rep (i, m + 1, n) {
		if (a[i] < 0) h2.push(a[i]);
		while (h2.size() && pre[i] + 2 * tag2 < pre[m] + tag) {
			tag2 -= h2.top(), h2.pop();
			cnt ++;
		}
	}
	cout << cnt << "\n";
}

int main() {
	int _; cin >> _;
	while (_ --) {
		solve();
	}
}