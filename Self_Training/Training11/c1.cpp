#include <bits/stdc++.h>

using i64 = long long;

const int N = 150, M = 2e4 + 10;

int s1[N][N], w1[N][N], dp[M];

int main() {
	int s, n, m;

	std::cin >> s >> n >> m;

	for(int i = 1; i <= s; i ++) {
		for(int j = 1; j <= n; j ++) {
			std::cin >> s1[j][i];
		}
	}

	for(int j = 1; j <= n; j ++)
		std::sort(s1[j] + 1, s1[j] + 1 + s);

	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= s1[i][1] * 2 + 1; j --) {
			for(int k = 1; k <= s; k ++) {
				if(j >= 2 * s1[i][k] + 1)
					dp[j] = std::max(dp[j], dp[j - (2 * s1[i][k] + 1)] + k * i);
			}
		}
	}

	std::cout << dp[m];
}