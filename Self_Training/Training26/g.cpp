#include <bits/stdc++.h>

using i64 = long long;

const int N = 400;

int n;

int w[N], g[N][N], p[N], d[N];

bool st[N];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

i64 prim(int s) {
	i64 ans = 0;

	memset(d, 0x3f, sizeof d);

	std::priority_queue<std::pair<int, int>> h1;

	h1.push({0, s});

	d[0] = 0;

	while (h1.size()) {
		int u = h1.top().second; h1.pop();

		if (st[u]) continue;

		st[u] = true;

		ans += d[u];

		for (int i = 0; i <= n; i ++) {
			if (st[i]) continue;

			int v = i, w = g[u][i];

			if (d[v] > w) {
				d[v] = w;
				h1.push({-d[v], v});
			}
		}
	}

	return ans;
}

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) p[i] = i;

	for (int i = 1; i <= n; i ++) std::cin >> w[i], g[0][i] = w[i];

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			std::cin >> g[i][j];

	std::cout << prim(0);
}