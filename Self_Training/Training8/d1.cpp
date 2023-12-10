#include <bits/stdc++.h>
#define siz(x) (int)x.size()
using i64 = long long;

int n, m;

const int N = 100, M = 3e4 + 2200, M2 = 1e4 + 10;

int f[N][M];

std::pair<int, int> fa[N];

std::vector<std::pair<int, int>> son[N];

int dp[M];

int main() {

	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		int vx, wx, px;
		std::cin >> vx >> wx >> px;

		wx *= vx;

		if(!px) fa[i] = {vx, wx};
		else {
			son[px].push_back({vx, wx});
		}
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= 0; j --) {
			int len = son[i].size();
			for(int k = 0; k < (1<<len); k ++) {
				int v = fa[i].first, w = fa[i].second;
				for(int l = 0; l < len; l ++) {
					if(k >> l & 1) {
						v += son[i][l].first;
						w += son[i][l].second;
					}
				}
				if(j >= v) {
					dp[j] = std::max(dp[j], dp[j - v] + w);
				}
			}
		}
	}

	std::cout << dp[m];
}