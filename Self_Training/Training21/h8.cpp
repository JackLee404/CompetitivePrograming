#include <iostream>

using i64 = long long;

const int N = 1e3 + 10, M = 2e4 + 10;

int n, m;

int dp[N * 32], v[N * 32], w[N * 32], cnt;

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		int v1, w1, s1;

		std::cin >> v1 >> w1 >> s1;

		for (int k = 1; k <= s1; k <<= 1) {
			v[++ cnt] = k * v1, w[cnt] = k * w1;
			s1 -= k;
		}
		if (s1 > 0) {
			v[++ cnt] = s1 * v1, w[cnt] = s1 * w1;
		}
	}

	for (int i = 1; i <= cnt; i ++) {
		for (int j = m; j >= v[i]; j --) {
			dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	// for (int i = 1; i <= cnt; i ++) {
	// 	for (int j = m; j >= v[i]; j --) {
	// 		dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
	// 	}
	// }

	std::cout <<  dp[m];
}