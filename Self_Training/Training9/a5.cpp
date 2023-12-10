#include <bits/stdc++.h>

using i64 = long long;

const int N = 200, M = 2e6 + 6e3;

int a[N], dp[M];

/*
	dp[i][j] 表示考虑前i个数，是否能组合出面值为j的数
*/

void solve() {
	int n, k = 0;
	std::cin >> n;

	memset(dp, 0, sizeof dp);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		k = std::max(a[i], k);
	}

	int ans = 0;

	std::sort(a + 1, a + n + 1);

	dp[0] = 1;

	for(int i = 1; i <= n; i ++) {
		if(!dp[a[i]]) ans ++;
		
		for(int j = a[i]; j <= k; j ++) {
			dp[j] |= dp[j - a[i]];
		}
	}

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;

	while(_ --) {
		solve();
	}
}