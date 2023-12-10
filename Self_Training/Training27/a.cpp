#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e5 + 10, M = N;

int n, k;

int h[N], e[M], ne[M], w[M], idx;

int depth[N], fa[N][17], sum[N], par[N], ans;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;	
}

void dfs(int u, int father, int dep) {
	depth[u] = dep;

	// std::cout << u << "\n";

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == father) continue;

		fa[v][0] = u;

		for (int k = 1; k <= 16; k ++) {
			fa[v][k] = fa[fa[v][k - 1]][k - 1];
		}

		dfs(v, u, dep + 1);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	for (int k = 16; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}

	if (a == b) return a;

	for (int k = 16; k >= 0; k --) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];	
		}
	}

	return fa[a][0];
}

int dfs2(int u, int fa) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		int s = dfs2(v, u);

		sum[u] += s;
	}

	ans = std::max(ans, sum[u]);

	return sum[u];
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n >> k;	

	for (int i = 1; i < n; i ++) {
		int x, y;
		
		std::cin >> x >> y;

		add(x, y);	
		add(y, x);
	}

	depth[0] = 0;
	dfs(1, -1, 1);

	// std::cout << lca(3, 2);

	while (k --) {
		int x, y;

		std::cin >> x >> y;

		int anc = lca(x, y);

		sum[x] += 1;
		sum[y] += 1;
		sum[anc] -= 1;

		if (fa[anc][0])
			sum[fa[anc][0]] -= 1;
	}

	// std::cout << sum[3] << "\n";

	dfs2(1, -1);

	std::cout << ans;
}

