#include <bits/stdc++.h>


using i64 = long long;

const int N = 500;

int m, n;

i64 a[N][N], dp[N][N], dp2[N][N];

int main() {
	std::cin >> m >> n;

	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
		}
	}

	memset(dp, -0x3f, sizeof dp);


	dp2[1][1] = 1;

	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (i == 1 && j == 1) {
				dp[i][j] = a[i][j];
				continue;
			}
			
			dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];



			if (i == 1 && j == 1) continue;

			if (dp[i - 1][j] == dp[i][j - 1]) {
				dp2[i][j] = dp2[i - 1][j] + dp2[i][j - 1];
			} else if (dp[i - 1][j] > dp[i][j - 1]) {
				dp2[i][j] = dp2[i - 1][j];
			} else {
				dp2[i][j] = dp2[i][j - 1];
			}
		}
	}	


	// for (int i = 1; i <= m; i ++) {
	// 	for (int j = 1; j <= n; j ++) {
	// 		std::cout << dp[i][j] << " \n"[j == n];
	// 	}
	// }	

	std::cout << dp[m][n] <<  " " << dp2[m][n];
}