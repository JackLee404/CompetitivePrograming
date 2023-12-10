#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = 2 * N;

int n, m;

int h[N], e[M], ne[M], w[M], idx;

int fa[N][17], depth[N];

i64 sum[N];

std::pair<int, int> ans;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dfs(int u, int father) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == father) continue;

		depth[v] = depth[u] + 1;

		fa[v][0] = u;

		for (int k = 1; k <= 16; k ++) {
			fa[v][k] = fa[fa[v][k - 1]][k - 1];
		}

		dfs(v, u);
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
			a = fa[a][k], b = fa[b][k];
		}
	}

	return fa[a][0];
}

int dfs2(int u, int father) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == father) continue;

		sum[u] += dfs2(v, u);
	}
	return sum[u];
}

void dfs3(int u, int father) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == father) continue;

		std::pair<int, int> t1 = std::make_pair(sum[v], w[i]);

		ans = std::max(ans, t1);

		dfs3(v, u);
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= n - 1; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b, i), add(b, a, i);
	}

	depth[0] = 0;
	depth[1] = 1;
	dfs(1, -1);

	for (int i = 1; i <= m; i ++) {
		int a, b, anc;

		std::cin >> a >> b;

		anc = lca(a, b);

		// std::cout << anc << "\n";
		
		sum[a] += 1, sum[b] += 1, sum[anc] -= 2;
	}

	dfs2(1, -1);

	// std::cout << sum[5] << "\n";

	dfs3(1, -1);
	
	std::cout << ans.second;
}