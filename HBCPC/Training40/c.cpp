#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = 2e5 + 10;

int h[N], ne[M], e[M], w[N], idx;

int depth[N], dp[N];

int n, m, k, p;

int S, T;

int ans = -0x3f3f3f3f;

bool st[N], st2[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs() {
	memset(depth, -1, sizeof depth);
	
	std::queue<int> q1;

	q1.push(S);

	depth[S] = 1;

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			if (depth[v] == -1) {
				depth[v] = depth[u] + 1;
				q1.push(v);
			}
		}
	}
}

bool dfs2(int u, int fa) {
	if (u == T) {
		return st[T] = true;
	}

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		if (depth[v] != depth[u] + 1) continue;

		st[u] |= dfs2(v, u);
	}

	return st[u];
}

void dfs(int u, int sum, int t) {
	if (!st[u]) {
		return;
	}

	if (t > k) t = 1;

	if (t == p) {
		sum += w[u];
	}
	
	if (u == T) {
		ans = std::max(sum, ans);
		return;
	}

	// std::cout << u << "\n";
	
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		// if (v == fa) continue;

		if (depth[v] == depth[u] + 1) {
			dfs(v, sum, t + 1);
		}	
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m >> k >> p;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	for (int i = 1; i <= m; i ++) {
		int u, v;
		
		std::cin >> u >> v;

		add(u, v), add(v, u);
	}

	std::cin >> S >> T;


	bfs();

	dfs2(S, -1);

	dfs(S, 0, 1);
}