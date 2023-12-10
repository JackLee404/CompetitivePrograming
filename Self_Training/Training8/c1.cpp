#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e2 + 10;

int n, m, root;

int v[N], w[N];

int ne[N], h[N], e[N], idx;

int dp[N][N];

void add(int a, int b) {
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

void dfs(int u) {
	for(int i = h[u]; ~i; i = ne[i]) {
		int son = e[i];
		
		dfs(son);

		for(int j = m - v[u]; j >= 0; j --) {
			for(int k = 0; k <= j; k ++) {
				dp[u][j] = std::max(dp[u][j], dp[u][j - k] + dp[son][k]);
			}
		}
	}

	for(int i = m; i >= v[u]; i --) dp[u][i] = dp[u][i - v[u]] + w[u];

	for(int i = 0; i < v[u]; i ++) dp[u][i] = 0;
}


int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		int p;
		std::cin >> v[i] >> w[i] >> p;

		if(p == -1) root = i;

		add(p, i);
	}

	dfs(root);

	std::cout << dp[root][m];
}