#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<int> a(n, 0), b(31, 0);
	for (int i = 0; i < n; i ++) {
		int x; cin >> x;
		for (int j = 0; j < 30; j ++) {
			b[j] += (x>>j&1);
		}
	}
	for (int i = 0; i < 31; i ++) {
		for (int j = n - 1, k = 1; k <= b[i]; k ++, j --) {
			a[j] += (1<<i);	
		}
	}
	for (int i = 0; i < n; i ++) {
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