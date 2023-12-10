#include <bits/stdc++.h>

using i64 = long long;

const int N = 110, M = N * 2;

int h[N], e[M], ne[M], w[M], idx;

int n, m;

int f[N][N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dfs(int u, int fa) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		dfs(v, u);

		for (int j = m; j >= 0; j --) {
			for (int k = 0; k < j; k ++) {
				f[u][j] = std::max(f[u][j], f[u][j - k - 1] + f[v][k] + w[i]);
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i < n; i ++) {
		int a, b, c;
		
		std::cin >> a >> b >> c;

		add(a, b, c), add(b, a, c);	
	}

	dfs(1, -1);


	std::cout << f[1][m];
}