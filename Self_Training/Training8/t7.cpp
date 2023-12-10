#include <bits/stdc++.h>

using i64 = long long;

int n, m, k;

const int N = 200, M = 1e3 + 10, K = 1e2;

int v[N], w[N];
int dp[N][M][K];

// dpijk 考虑前i个物品，当精灵球数量为j时的 最小血量减少量
// 

int main() {
	std::cin >> n >> m >> k;

	for(int i = 1; i <= k; i ++) {
		std::cin >> v[i] >> w[i];
	}

	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(j < v[i]) {
				dp[i][j] = dp[i - 1][j];
			} else {
				
			}
		}
	}
}