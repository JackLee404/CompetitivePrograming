#include <iostream>

using i64 = long long;

const int N = 1e3 + 10, M = 200;

int v1[N], v2[N], w[N];

int dp[M][M];


int main() {
	int n, v, m;
	std::cin >> n >> v >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v1[i] >> v2[i] >> w[i];
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = v; j >= v1[i]; j --) {
			for(int k = m; k >= v2[i]; k --) {
				dp[j][k] = std::max(dp[j][k], dp[j - v1[i]][k - v2[i]] + w[i]);
			}
		}
	}

	std::cout << dp[v][m];
}