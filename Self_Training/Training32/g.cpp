#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10, M = 4e5 + 10;

int n;

int h[N], e[M], ne[M], w[M], idx;

int v1[N], v2[N], cnt;
i64 dist[N];

bool st[N];

i64 ans;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dfs(int u, int j) {
	st[u] = true;
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (st[v]) continue;

		if (j != -1 && w[j] > w[i]) dist[v] = dist[u] + 1;
		else dist[v] = dist[u];

		ans = std::max(ans, dist[v]);

		dfs(v, i);
	}
}

void solve() {
	memset(h, -1, sizeof h);
	memset(dist, 0, sizeof dist);
	memset(st, false, sizeof st);

	ans = 1, idx = 0;

	std::cin >> n;

	for (int i = 1; i < n; i ++) {
		int u, v;

		std::cin >> u >> v;

		add(u, v, i), add(v, u, i);
	}
	
	dist[1] = 1;

	dfs(1, -1);

	std::cout << ans << "\n";
}


int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}