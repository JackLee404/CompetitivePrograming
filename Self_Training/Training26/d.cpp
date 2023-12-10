#include <bits/stdc++.h>

using i64 = long long;

int n, m, ti, tj, tm;

i64 ans;

i64 g[110][110], val[110][110];

int p[110][110];

std::vector<int> res;

void path(int i, int j) {
	if (!p[i][j]) return;
	int k = p[i][j];
	path(i, k);
	// std::cout << k << " ";
	res.push_back(k);
	path(k, j);
}

void floyd() {
	ans = 0x3f3f3f3f;

	memcpy(val, g, sizeof g);

	for (int k = 1; k <= n; k ++) {

		for (int i = 1; i < k; i ++) {
			for (int j = 1; j < i; j ++) {
				// ans = std::min(ans, g[i][j] + val[i][k] + val[k][j]);
				if (ans > g[i][j] + val[i][k] + val[k][j]) {
					ti = i, tj = j, tm = k;
					
					ans = g[i][j] + val[i][k] + val[k][j];

					res.clear();
					res.push_back(i);
					res.push_back(k);
					res.push_back(j);					
					path(j, i);					
				}		
			}
		}

		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				// g[i][j] = std::min(g[i][j], g[i][k] + g[k][j]);
				if (g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];	
					p[i][j] = k;
				}
			}
		}
		
	}
}

 
int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			g[i][j] = (i == j)?0:0x3f3f3f3f;
		}
	}

	while (m --) {
		i64 a, b, c;

		std::cin >> a >> b >> c;

		g[a][b] = g[b][a] = std::min(c, g[a][b]);
	}

	floyd();

	if (ans == 0x3f3f3f3f) {
		return puts("No solution."), 0;
	}

	for (int i = 0; i < res.size(); i ++) {
		std::cout << res[i] << " \n"[i == (int) res.size() - 1];
	}
}