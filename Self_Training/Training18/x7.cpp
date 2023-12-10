#include <bits/stdc++.h>

using i64 = long long;

const int N = 100;

int w[N], dp[N][N];

void solve() {
	int n, c1, c2;

	std::unordered_map<int, bool> h1;

	std::cin >> n >> c1 >> c2;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	bool ok = true;

	while (ok) {
		ok = false;
		for (int i = 1; i <= n; i ++) {
			if(!h1[i]) {
				memcpy(dp[i], dp[i - 1], sizeof dp[i - 1]);
				continue;
			}
			ok = true;
			for (int k = 1; k <= c1; k ++) {
				dp[i][k] = dp[i - 1][k];

				if (k >= w[i]) {
					if (dp[i - 1][k - w[i]] + 1 > dp[i][k]) {
						h1[i] = true;
					}

					dp[i][k] = std::max(dp[i][k], dp[i - 1][k - w[i]] + 1);
				}
			}
		}

		if (ok) {
			
		}
	}
}

int main() {
	int t;

	std::cin >> t;

	while (t --) {
		solve();
	}
}
