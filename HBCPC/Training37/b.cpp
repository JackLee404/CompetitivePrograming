#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e4 + 10, M = N * 2, INF = 0x3f3f3f3f;

int h[N], e[M], ne[M], w[M], idx;

int d1[N], d2[N], p1[N], p2[N], up[N];

bool leaf[N];

int n;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

int dfs1(int u, int fa) {
	if (h[u] == -1) {
		return leaf[u] = true, 0;
	}

	d1[u] = d2[u] = -INF;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		int d = dfs1(v, u) + w[i];

		if (d >= d1[u]) {
			d2[u] = d1[u], d1[u] = d;
			p1[u] = v;	
		}
		else if (d > d2[u]) d2[u] = d;
	}
	
	return d1[u];
}

void dfs2(int u, int fa) {

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		if (p1[u] == v) up[v] = std::max(up[u], d2[u]) + w[i];
		else up[v] = std::max(up[u], d1[u]) + w[i];

		dfs2(v, u);
	}
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n;

	for (int i = 1; i <= n - 1; i ++) {
		int a, b, c;	

		std::cin >> a >> b >> c;

		add(a, b, c), add(b, a, c);
	}

	dfs1(1, -1);
	dfs2(1, -1);
	

	int ans = INF;

	for (int i = 1; i <= n; i ++) {
		if (leaf[i]) {
			ans = std::min(ans, up[i]);
		} else ans = std::min(ans, std::max(up[i], d1[i]));
	}

	std::cout << ans;
}