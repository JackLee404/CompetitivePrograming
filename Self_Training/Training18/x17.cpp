#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10;

int n, m, dist[N], w[N];

struct node {
	int v, c;
};

bool st[N];

std::vector<node> g[N];

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	std::priority_queue<std::pair<int, int>> h1;
	dist[s] = 0;
	h1.push({0, s});

	while(h1.size()) {
		auto t = h1.top(); h1.pop();

		int u = t.second;

		if (st[u]) continue;
		st[u] = true;

		for (auto &x: g[u]) {
			int v = x.v, w1 = x.c;
			if (dist[v] > dist[u] + w1 + w[v]) {
				h1.push({-dist[v], v});
				dist[v] = dist[u] + w1 + w[v];
			}
		}	
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	for (int i = 1; i <= m; i ++) {
		int x, y, c;
		
		std::cin >> x >> y >> c;

		g[x].push_back({y, c});
		g[y].push_back({x, c});
	}

	dijkstra(1);

	// for (int i = 1; i <= n; i ++) {
	// 	std::cout << dist[i] << " \n"[i == n];
	// }

	if(n == 1) {
		std::cout << 0;
	} else std::cout << dist[n] - w[n] << "\n";
}