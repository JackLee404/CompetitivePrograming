#include <iostream>

using i64 = long long;

const int N = 1e3 + 10;

int v[N], w[N], s[N];

int dp[N][N];

int q[N];

int main() {
	int n, m;
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i] >> w[i] >> s[i];
	}

	for(int i = 1; i <= n; i ++) {
		if(!s[i] || s[i] == -1) {
			for(int j = 1; j <= m; j ++) {
				if(j >= v[i]) {
					dp[i][j] = std::max(dp[i - 1][j], dp[i - !s[i]][j - v[i]] + w[i]);
				} else {
					dp[i][j] = dp[i - 1][j];
				}
			}
		} else {
			for(int r = 0; r < v[i]; r ++) {
				int hh = 0, tt = -1;
				for(int k = r; k <= m; k += v[i]) {
					if(hh <= tt && k - q[hh] > s[i] * v[i]) hh ++;				
					while(hh <= tt && dp[i - 1][q[tt]] + (k - q[tt]) / v[i] * w[i] <= dp[i - 1][k]) tt --;
					q[++ tt] = k;
					dp[i][k] = dp[i - 1][q[hh]] + (k - q[hh]) / v[i] * w[i];
				}
			}
		}
	}

	std::cout << dp[n][m];
}