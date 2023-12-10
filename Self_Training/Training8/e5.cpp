#include <iostream>

using i64 = long long;

const int N = 3e4 + 10;

int dp[N];

int main() {
	int n, m;

	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		int v, w;
		std::cin >> v >> w;

		w *= v;

		for(int j = m; j >= v; j --) {
			dp[j] = std::max(dp[j], dp[j - v] + w);
		}
	}

	std::cout << dp[m];
}