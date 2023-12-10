#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e5 + 10, M = N * 2;

int n, m;

int h[N], e[M], ne[M], idx;

int fa[N][19], depth[N], sum[M];

int a[N];

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

		for (int k = 1; k <= 18; k ++) {
			fa[v][k] = fa[fa[v][k - 1]][k - 1];
		}

		dfs(v, u, dep + 1);
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	for (int k = 18; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}

	if (a == b) return b;

	for (int k = 18; k >= 0; k --) {
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

		sum[u] += dfs2(v, u);
	}

	return sum[u];
}


int main() {
	memset(h, -1, sizeof h);

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n - 1; i ++) {
		int x, y;
		
		std::cin >> x >> y;	

		add(x, y);
		add(y, x);
	}

	depth[0] = 0;
	dfs(1, -1, 1);

	for (int i = 2; i <= n; i ++) {
		int x = a[i - 1], y = a[i];

		sum[x] += 1;
		
		sum[y] += 1;

		int anc = lca(x, y);

		sum[anc] -= 1;

		sum[fa[anc][0]] -= 1;
	}	
	
	dfs2(1, -1);

	sum[a[1]] ++;

	for (int i = 1; i <= n; i ++) {
		std::cout << sum[i] - 1 << "\n";
	}
}