#include <bits/stdc++.h>

using i64 = long long;

const int N = 3000, mod = 1e9 + 7;

int n, m;

int dp[N][N];

bool vis[N][N];

int main() {
	std::cin >> n >> m;

	dp[1][1] = 1;

	for(int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		vis[x][y] = true;
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == 1 && j == 1) continue;

			if (vis[i][j]) {
				continue;
			}

			if(!vis[i - 1][j])
				dp[i][j] = ((i64)dp[i][j] + dp[i - 1][j]) % mod;

			if(!vis[i][j - 1])
				dp[i][j] = ((i64)dp[i][j] + dp[i][j - 1]) % mod;

			
		}
	}

	// for(int i = 0; i <= n; i++) {
	// 	for(int j = 0; j <= n; j++) {
	// 		std::cout << dp[i][j] << " \n"[j == n];
	// 	}
	// }

	std::cout << dp[n][n];
}