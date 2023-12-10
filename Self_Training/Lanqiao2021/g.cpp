#include <iostream>
#include <algorithm>

using i64 = long long;

const int M = 1e5 + 10;

i64 dp[230][M], v[300], ans;

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i];
	}

	for(int i = 0; i <= n; i ++)
		dp[0][0] = 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= M - 10; j ++) {
			dp[i][j] = dp[i - 1][j] + dp[i - 1][j + v[i]];

			if(j - v[i] >= 0)
				dp[i][j] += dp[i - 1][j - v[i]];
		}
	}

	for(int i = 1; i <= M - 10; i ++) {
		ans += (dp[n][i]?1:0);
	}

	std::cout << ans;
}