#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

const int N = 1e3 + 10;

int v[N], w[N], dp[N][N], val[N][N];

/*
	dp[i][j] 表示考虑前i个物品, 当背包容量为j时的最大容量

	在保证最大容量的前提下， 考虑最小价值（伤害）

	若伤害大于阈值， 则不进行操作


	dp[i][j] 表示考虑前i个物品，当背包容量为j时的最大容量的最小价值
*/

int main() {
	int n, m, k;
	std::cin >> n >> m >> k;

	for(int i = 1; i <= k; i ++) {
		std::cin >> v[i] >> w[i];
	}

	// memset(dp, 0x3f, sizeof dp);

	rep(i, 1, n) {
		rep(j, 1, k) {
			if(j >= v[i]) {
				dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - v[i]] + 1);

				if(dp[i - 1][j - v[i]] + 1 > dp[i - 1][j]) {
					val[i][j] = val[i - 1][j - v[i]] + w[i];
				} else if(dp[i - 1][j - v[i]] + 1 < dp[i - 1][j]) {
					val[i][j] = val[i - 1][j];
				} else {
					val[i][j] = std::min(val[i - 1][j], val[i - 1][j - v[i]] + w[i]);
				}
			} else {
				dp[i][j] = dp[i - 1][j];
				val[i][j] = val[i - 1][j];
			}
		}
	}

	std::cout << dp[n][m] << " ";
}