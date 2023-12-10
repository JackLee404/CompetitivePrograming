#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e3 + 10;

int n;

int a[N][N], dp[N][N];

// int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

/*
	dp[x][y] 表示从xy跳的最优解
*/

int dfs(int x, int y) {
	if (x > n) return 0;

	int res = 0x3f3f3f3f;

	if (dp[x][y] != -1) return dp[x][y];

	if (x != n) {
		for (int i = 1; i <= n; i ++) {
			if (i == y) continue;
			res = std::min(res, a[x][y] + dfs(x + 1, i));
		}
	} else return dp[x][y] = a[x][y];

	return dp[x][y] = res;
}

int main() {
	memset(dp, -1, sizeof dp);

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
		}
	}

	int ans = 0x3f3f3f3f;

	for (int i = 1; i <= n; i ++) dfs(1, i);

	for (int i = 1; i <= n; i ++) {
		if (dp[1][i] == 0x3f3f3f3f) continue;
		ans = std::min(ans, dp[1][i]);
	}

	std::cout << ans;
}