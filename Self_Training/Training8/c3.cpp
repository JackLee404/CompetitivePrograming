#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int dp[N][N], v[N], w[N];

int main() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i] >> w[i];
	}

	for(int i = n; i >= 1; i --) {
		for(int j = 0; j <= m; j ++) {
			dp[i][j] = dp[i + 1][j];
			if(j >= v[i])
				dp[i][j] = std::max(dp[i][j], dp[i + 1][j - v[i]] + w[i]);
		}
	}

	int v1 = m;

	std::vector<int> ans;

	for(int i = 1; i <= n; i ++) {
		if(v1 >= v[i] && dp[i][v1] == dp[i + 1][v1 - v[i]] + w[i]) {
			ans.push_back(i);
			v1 -= v[i];
		}
	}

	for(int i = 0; i < ans.size(); i ++) {
		std::cout << ans[i] << " \n"[i == (int) ans.size() - 1];
	}
}