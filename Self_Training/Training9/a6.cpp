#include <bits/stdc++.h>

using i64 = long long;

const int M = 500;

int dp[M][M];

/*
	简单二维费用背包
*/

void solve() {
	int n, M, T;
	std::cin >> n >> M >> T;

	for(int i = 1; i <= n; i ++) {
		int m, t;
		std::cin >> m >> t;

		for(int j = M; j >= m; j --) {
			for(int k = T; k >= t; k --) {
				dp[j][k] = std::max(dp[j][k], dp[j - m][k - t] + 1);
			}
		}
	}

	std::cout << dp[M][T];
}

int main() {
	int _;
	// std::cin >> _;
	_ = 1;
	while(_ --) {
		solve();
	}
}