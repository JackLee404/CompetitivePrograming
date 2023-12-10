#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(n + 1));
	std::vector<std::vector<int>> dp(n + 1, std::vector<int>(n + 1));

	rep(i, 1, n)
		rep(j, 1, n)
			std::cin >> a[i][j];

	rep(i, 1, n) {
		rep(j, 1, n) {
			if(i - 1 > 0 && j - 1 > 0)
				dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + a[i][j];
			else if(i - 1 > 0) {
				dp[i][j] = dp[i - 1][j] + a[i][j];
			} else if(j - 1 > 0) {
				dp[i][j] = dp[i][j - 1] + a[i][j];
			} else {
				dp[i][j] = a[i][j];
			}
		}
	}

	std::cout << dp[n][n] << "\n";
}

int main() {
	int _;
	_ = 1;
	while(_ --) {
		solve();
	}
}