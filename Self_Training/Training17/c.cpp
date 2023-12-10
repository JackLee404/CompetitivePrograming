#include <iostream>
#include <cstring>
#include <queue>

using i64 = long long;

int n, m;

int e[3000], h[600], ne[3000], w[3000], idx;

int dist[3000];

bool st[3000];

void add(int a, int b, int c) {
	w[idx] = c, ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

int dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);

	std::priority_queue<std::pair<int, int>> h1;

	h1.push({0, s});

	dist[s] = 0;

	while (h1.size()) {
		auto t = h1.top(); h1.pop();

		int v = t.second;

		if (st[v]) continue;

		st[v] = true;

		// std::cout << v << "\n";

		for (int i = h[v]; ~i; i = ne[i]) {
			// std::co
			int u1 = e[i], w1 = w[i];
			if (dist[u1] > dist[v] + w1) {

				dist[u1] = dist[v] + w1;

				// if (!st[u1]) {
					h1.push({-dist[u1], u1});
				// }
			}
		}
	}

	int ans = -1;

	for (int i = 1; i <= n; i ++) {
		if (dist[i] >= 0x3f3f3f3f / 2) {
			return -1;
		}

		ans = std::max(ans, dist[i]);
	}

	return ans;
}

int main() {
	memset(h, -1, sizeof h);
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		int a, b, d;

		std::cin >> a >> b >> d;

		add(a, b, d);
		add(b, a, d);
	}

	std::cout << dijkstra(1);
}