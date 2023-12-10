#include <bits/stdc++.h>

using i64 = long long;

/*
	dp[i][j] 表示考虑a序列前i个数，b序列前j个数的最连续子序列
*/

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n), b(n), ct1(2 * n + 1, 0), ct2(2 * n + 1, 0);

	for (auto &x: a) std::cin >> x;

	for (auto &x: b) std::cin >> x;

	int cnt1 = 1, cnt2 = 1;

	a.push_back(2 * n + 1), b.push_back(2 * n + 1);

	for (int i = 1; i <= n; i ++) {
		if (a[i] == a[i - 1]) cnt1 ++;
		else ct1[a[i - 1]] = std::max(ct1[a[i - 1]], cnt1), cnt1 = 1;

		if (b[i] == b[i - 1]) cnt2 ++;
		else ct2[b[i - 1]] = std::max(ct2[b[i - 1]], cnt2), cnt2 = 1;
	}

	int ans = 1;

	for (int i = 1; i <= 2 * n; i ++) {
		ans = std::max(ans, ct1[i] + ct2[i]);
	}

	std::cout << ans << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}