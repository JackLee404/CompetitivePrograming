#include <bits/stdc++.h>
#include <cstring>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using i64 = long long;

const int N = 150;

int dp[N][N], v[N], w[N];

// 完全背包问题
// dp[i][j] 表示考虑前i个物品，当箱子容量为V时的最小剩余空间
// dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]];

void solve() {
	int n, m;
	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i];
	}

	memset(dp, 0x3f, sizeof dp);

	for(int i = 0; i <= m; i ++) {
		dp[0][i] = i;
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++){
			dp[i][j] = dp[i - 1][j];
			if(j >= v[i]) {
				dp[i][j] = std::min(dp[i][j], dp[i - 1][j - v[i]]);
			}
		}
	}
	std::cout << dp[n][m];
}

int main() {
	int _;
	_ = 1;
	while(_ --) {
		solve();
	}
}