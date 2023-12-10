#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

void solve() {
	int r, c;
	std::cin >> r >> c;

	std::vector<std::vector<int>> a(r + 1, std::vector<int>(c + 1));

	std::vector<std::vector<int>> dp(r + 1, std::vector<int>(c + 1));

	rep(i, 1, r) {
		rep(j, 1, c) {
			std::cin >> a[i][j];
		}
	}

	rep(i, 1, r) {
		rep(j, 1, c) {
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
		}
	}

	std::cout << dp[r][c] << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}