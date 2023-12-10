#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

// n <= m 时取两个序列最大的n个
// n > m  时

void solve() {
	long long sum = 0;
	int n, m, cnt = 0;
	cin >> n >> m;
	// vector<int> v1(n);
	// for (auto &x: v1) 
	// 	cin >> x;

	// sort(v1.begin(), v1.end());

	// for (int i = 0; i < m; i ++) {
	// 	int t; cin >> t;
	// 	if (cnt < n) {
	// 		v1[cnt] = t, cnt ++;
	// 		if (v1[)
	// 	} else if (cnt == n) {
	// 		cnt = 0, sort(v1.begin(), v1.end());
	// 	}
	// }

	// for (int i = cnt; i < n; i ++) {
	// 	sum += v1[i];
	// }
	// for (int i = 0; i < v1.size(); i ++) {
	// 	if (i < v1.size()) {
	// 		sum += max(v1[i], v2[i]);	
	// 	}
	// }
	priority_queue<int, vector<int>, greater<int>> p1; 
	for (int i = 1; i <= n; i ++) {
		int t; cin >> t, p1.push(t);
	}
	for (int j = 1; j <= m; j ++) {
		int t; cin >> t;
		p1.pop(), p1.push(t);
	}
	while (p1.size()) {
		sum += p1.top(), p1.pop();	
	}
	cout << sum << endl;
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}