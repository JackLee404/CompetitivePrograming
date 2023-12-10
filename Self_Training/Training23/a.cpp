#include <iostream>
#include <cstring>
#include <queue>
#define debug(x) std::cout << x << "\n"
using i64 = long long;

const int N = 1e3 + 10, M = 2e4 + 1010;

int n, m, s;

int h[N], e[M], w[M], ne[M], idx;

int dist[N];

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);

	std::priority_queue<std::pair<int, int>> h1;

	dist[s] = 0;

	h1.push({0, s});

	while (h1.size()) {
		auto t = h1.top(); h1.pop();

		int u = t.second;

		if (st[u]) continue;

		st[u] = true;

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			if (dist[v] > dist[u] + w[i]) {
				dist[v] = dist[u] + w[i];
				h1.push({-dist[v], v});
			}
		}
	}
}

int main() {
	while (std::cin >> n >> m >> s) {
		memset(h, -1, sizeof h);
		idx = 0;
		
		for (int i = 1; i <= m; i ++) {
			int p, q, t;

			std::cin >> p >> q >> t;

			add(p, q, t);
		}

		int w;

		std::cin >> w;

		for (int i = 1; i <= w; i ++) {
			int k;
			std::cin >> k;

			add(0, k, 0);
		}

		dijkstra(0);

		if (dist[s] == 0x3f3f3f3f) std::cout << -1 << "\n";
		else std::cout << dist[s] << "\n";
	}
}