#include <iostream>

using i64 = long long;

const int N = 20;

int v[N][N], w[N][N], dp[N][N], path[N];

int main() {
	int n, m;
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> w[i][j];
		}
	}

	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++) {
			dp[i][j] = dp[i - 1][j];
			for(int k = 1; k <= m; k ++) {
				if(j >= k) {
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k] + w[i][k]);
				}
			}
		}
	}

	int j = m;
	for(int i = n; i > 0; i --) {
		for(int k = 0; k <= j; k ++) {
			if(dp[i][j] == dp[i - 1][j - k] + w[i][k]) {
				path[i] = k;
				j -= k;
				break;
			}
		}
	}

	std::cout << dp[n][m] << "\n";


	for(int i = 1; i <= n; i ++) {
		std::cout << i << " " << path[i] << "\n";
	}
}