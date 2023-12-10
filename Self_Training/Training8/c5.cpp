#include <bits/stdc++.h>

using i64 = long long;

int n, m, cn;

const int N = 100, M = 3e4 + 2200, M2 = 1e4 + 10;

int v[N], w[N];

int f[N][M];

int dp[M];

std::vector<std::pair<int, int>> v1[N];


int main() {

	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		int v2, w2, p;
		std::cin >> v2 >> w2 >> p;

		v2 *= w2;

		if(p) {
			v1[p].push_back({v2, w2});
		} else {
			v[++ cn] = v2;
			w[cn] = w2;
		}
	}

	for(int i = 1; i <= cn; i ++) {
		for(int j = m; j >= v[i]; j --) {
			int len = v1[i].size();
			len --;
			for(int S = 0; S < (1ll<<len); S ++) {
				int val = w[i], v2 = 0;
				for(int k = 0; k < len; k ++) {
					if(S >> k & 1) {
						val += v1[i][k].second;
						v2 += v1[i][k].first;
					}
				}
				if(j >= v2)
					dp[j] = std::max(dp[j], dp[j - v2] + val);
			}
			dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
		}
	}

	std::cout << dp[m];
}