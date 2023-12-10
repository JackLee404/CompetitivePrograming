#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n, m, k;

	std::cin >> n >> m >> k;

	std::vector<std::vector<int>> G(n + 1);

	for (int i = 1; i <= m; i ++) {
		int u, v;
		
		std::cin >> u >> v;

		G[u].push_back(v);
		G[v].push_back(u);		
	}

	std::vector<int> dis(n + 1, -1), par(n + 1), inner(n + 1);
	std::queue<int> q;

	i64 ans = 1;

	q.push(1), dis[1] = 0;

	while (q.size()) {
		int u = q.front(); q.pop();
		for (auto v: G[u]) {
			if (dis[v] == -1) continue;
			q.push(v);
			dis[v] = dis[u] + 1;
			par[v] = u;
			inner[u] = 1;
		}
	}

	for (int u = 2; u <= n; u ++) {
		if (dis[u] == -1 || dis[u] > k) continue;

		i64 cnt = 0;

		for (auto v: G[u]) {
			if (v == par[u] || par[v] == u) continue;

			cnt ++;
		}

		if (!inner[u]) cnt = std::max(cnt, 1ll);

		ans += (k - dis[u]) * cnt + 1;
	}

	std::cout << ans;
}