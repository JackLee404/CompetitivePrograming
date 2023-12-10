#include <bits/stdc++.h>

using i64 = long long;

/*
	dp[i][j] 表示考虑前i个物品, 当容量数严格等于j时的方案数
	dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i]];
*/

const int N = 120, M = 1e4 + 10;

int dp[N][M], v[N];

int main() {
	int n, m;
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i];
	}

	for(int i = 0; i <= n; i ++) {
		dp[i][0] = 1;
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dp[i][j] = dp[i - 1][j];
			if(j >= v[i])
				dp[i][j] = dp[i - 1][j] + dp[i - 1][j - v[i]];
		}
	}

	std::cout << dp[n][m];
}