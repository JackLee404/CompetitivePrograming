#include <bits/stdc++.h>

using i64 = long long;

const int N = 110, M = 510, K = 1010;

int n, m, k;


int dp[N][K][M], hp[N][K][M];

int v[N], h[N];

// dpijk 表示考虑前i个精灵，当背包容量为j时, 皮卡丘的hp为k时，的最大精灵球数量, 并且保证皮卡丘hp最大

/*

	将集合划分为，选第i个物品和不选第i个物品，则有转移方程：

	则dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - v[i]][k - v2[i]] + 1);
*/


int main() {
	std::cin >> n >> m >> k;

	for(int i = 1; i <= k; i ++) {
		std::cin >> v[i] >> h[i];
	}

	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++) {
			for(int l = 1; l <= m; l ++) {
				if(j >= v[i] && l >= h[i]) {
					int &a = dp[i - 1][j - v[i]][k - h[i]], &b = hp[i - 1][j - 1][k - h[i]];
					if(dp[i - 1][j][k] == a + 1) {
						dp[i][j][k] = a + 1;
						hp[i][j][k] = std::max(hp[i - 1][j][k], b);
					} else if(dp[i - 1][j][k] < a + 1) {
						dp[i][j][k] = a + 1;
						hp[i][j][k] = b;
					} else {
						dp[i][j][k] = dp[i - 1][j][k];
						hp[i][j][k] = hp[i - 1][j][k];
					}
				}
			}
		}
	}

	std::cout << dp[k][n][m] << " " << hp[k][n][m];
}