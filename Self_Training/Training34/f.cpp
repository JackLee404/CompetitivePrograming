#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int n, k;

int a[N], count[N], dp[N], val[N];

int main() {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) std::cin >> a[i], count[a[i]] ++;

	int ans = 0;

	if (!k) {
		for (int i = 1; i <= 1e5; i ++) {
			ans += (count[i] >= 1);
		}
	} else {
		for (int i = 0; i < k; i ++) {
			memset(dp, 0, sizeof dp);
			int cnt = 1;

			for (int j = i; j <= 1e5; j += k) {
				val[++ cnt] = count[j];
			}

			for (int j = 2; j <= cnt; j ++) {
				dp[j] = std::max(dp[j - 1], dp[j - 2] + val[j]);
			}

			ans += dp[cnt];
		}

	}

	std::cout << ans;
}