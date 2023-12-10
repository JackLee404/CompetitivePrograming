#include <iostream>
using i64 = long long;

const int N = 2001;

int n;

i64 a[N][N], dp[N][N], ans;

i64 f1[N][N], f2[N][N];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", &a[i][j]);
		}
	}

	// memset(f1, 0x3f, sizeof f1);
	// memset(f2, 0x3f, sizeof f2);
	// memset(dp, 0x3f, sizeof dp);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dp[i][j] = 0x3f3f3f3f;
			if (i == 1) {
				dp[i][j] = a[i][j];
			} else {
				dp[i][j] = std::min(dp[i][j], a[i][j] + std::min(f1[i - 1][j - 1], f2[i - 1][j + 1]));
			}
		}

		f1[i][0] = f2[i][n + 1] = 0x3f3f3f3f;

		for (int j = 1, k = n; j <= n; j ++, k --) {
			f1[i][j] = std::min(dp[i][j], f1[i][j - 1]);
			f2[i][k] = std::min(dp[i][k], f2[i][k + 1]);
		}
	}

	std::cout << f1[n][n];
}