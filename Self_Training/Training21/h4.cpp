#include <iostream>

using i64 = long long;

i64 dp[40][40];

bool check(int i, int j) {
	return (i % 2 == 0) && (j % 2 == 0);
}

int main() {
	int n, m;

	std::cin >> n >> m;


	dp[1][1] = 1;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (check(i, j)) continue;

			// if (!check(i - 1, j)) 
				dp[i][j] += dp[i - 1][j];
			// if (!check(i, j - 1)) 
				dp[i][j] += dp[i][j - 1];
			
		}
	}

	// for (int i = 1; i <= n; i ++) {
	// 	for (int j = 1; j <= m; j ++) {
	// 		std::cout << dp[i][j] << " \n"[j == m];
	// 	}
	// }

	std::cout << dp[n][m];
}