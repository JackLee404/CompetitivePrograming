#include <bits/stdc++.h>

using namespace std;

void solve() {
	int n; cin >> n;
	vector<long long> a(n);
	for (auto &x: a) cin >> x;
	for (int i = 0; i < a.size(); i ++) {
		if (i) {
			a[i] = a[i] * a[i - 1];
			a[i - 1] = 1;
		}
	}
	long long res = accumulate(a.begin(), a.end(), 0ll);
	cout << 2022ll * res << endl;
}

int main() {
	int _;
	cin >> _;
	while(_ --) {
		solve();
	}
}