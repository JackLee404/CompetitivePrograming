#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = 2 * N;

int n, m;

int h[N], e[M], ne[M], w[M], idx;

int fa[N][18], depth[N], sum[M];

i64 ans;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void dfs(int u, int father, int dep) {
	depth[u] = dep;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == father) continue;

		depth[v] = depth[u] + 1;

		fa[v][0] = u;

		for (int k = 1; k <= 17; k ++) {
			fa[v][k] = fa[fa[v][k - 1]][k - 1];
		}

		dfs(v, u, dep + 1);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	for (int k = 17; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}

	if (a == b) return b;

	for (int k = 17; k >= 0; k --) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}

	return fa[a][0];
}

int dfs2(int u, int fa) {
	int res = sum[u];

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		int s = dfs2(v, u);

		if (s == 0) ans += m;
		else if (s == 1) ans ++;

		res += s;
	}

	return res;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= n - 1; i ++) {
		int x, y;
		
		std::cin >> x >> y;	

		add(x, y);
		add(y, x);
	}

	depth[0] = 0;

	dfs(1, -1, 1);

	for (int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		sum[x] += 1;
		sum[y] += 1;
		sum[lca(x, y)] -= 2;
	}
	

	dfs2(1, -1);

	std::cout << ans;
}