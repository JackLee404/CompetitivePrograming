#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e3 + 100;

int a[N], b[N], dp[N][N];

/*
	dp[i][j] 表示a序列前i个数，和b序列前j个数构成的公共子序列的最大长度

	if(a[i] == a[j]) dp[i][j] = std::max(dp[i - 1][j - 1] + 1, dp[i - 1][j], dp[i][j - 1]);

	d
*/

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for(int j = 1; j <= n; j ++) {
		std::cin >> b[j];
	}

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(a[i] != b[j]) continue;

			dp[i][j] = 1;

			for(int k = 1; k < j; k ++) {
				if(b[k] < b[j] && b[k] == a[i - 1]) {
					dp[i][j] = std::max(dp[i][j], dp[i][k] + 1);
				}
			}

			for(int k = 1; k < i; k ++) {
				if(a[k] < a[i] && a[k] == b[j - 1]) {
					dp[i][j] = std::max(dp[i][j], dp[k][j] + 1);
				}
			}

			ans = std::max(ans, dp[i][j]);
		}
	}

	std::cout << ans;
}