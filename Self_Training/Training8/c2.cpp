#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e4 + 10;

int v[N], w[N];

int dp[1010][1010];

int main() {
	int n, m;

	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i] >> w[i];	
	}

	memset(dp, -1, sizeof dp);

	for(int i = 0; i <= n; i ++) {
		dp[i][0] = 0;
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i]] + v[i] * w[i]);
		}
	}

	std::cout << dp[n][m];
}