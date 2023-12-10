#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define sz(x) (int)x.size()
using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1), p(n + 1);

	int ave = 0, ans = 0;

	FOR(i, 1, n) {
		std::cin >> a[i];
		ave += a[i];
	}

	ave /= n;

	FOR(i, 1, n) {
		p[i] = a[i] - ave;
	}

	int j = 1;
	FOR(i, 1, n) {
		if(p[i] != 0) {
			p[i + 1] += p[i];
			ans ++;
		}
	}

	std::cout << ans << "\n";
}

int main() {
	int _;

	// std::cin >> _;
	_ = 1;
	while(_ --) {
		solve();
	}
}