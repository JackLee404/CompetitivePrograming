#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, cnt = 0, sum[2030];

bool st[2030];

vector<int> v1;

bool prime(int x) {
	if (x < 2) return false;
	for (int i = 2; i * i <= x; i ++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

int ans = -1;


void dfs(int x, int cnt) {
	if (x < 0) return;
	if (x == 0) {
		cout << cnt << endl;
		ans = max(cnt, ans);
	}
	for (int i = 1; i < (int) v1.size(); i ++) {
		if (st[i]) continue;
		st[i] = true;
		dfs(x - i, cnt + 1);
		st[i] = false;
	}
}

int main() {
	v1.push_back(0);
	for (int i = 2; i <= 2020; i ++) {
		if (prime(i)) v1.push_back(i);
	}

	cin >> n;
	// for (int i = 2; ; i ++) {
	// 	if (prime(i)) {
	// 		cnt ++;
	// 		n -= i;
	// 		cout << i << endl;
	// 	}
	// 	if (n == 0) {
	// 		break;
	// 	}
	// }
	dfs(n, 0);
	cout << ans << endl;
}