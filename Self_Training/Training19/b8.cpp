#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using i64 = long long;

const int N = 600;

int n, p, c;

struct node {int v, w;};

std::vector<node> g[N];

bool st[N];

int dist[N], pos[N];

int dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);
	
	std::priority_queue<std::pair<int, int>> h1;

	h1.push({0, s});

	dist[s] = 0;

	while (h1.size()) {
		auto t = h1.top(); h1.pop();
		int u = t.second;

		if (st[u]) continue;

		st[u] = true;

		for (auto x: g[u]) {
			int v = x.v, w = x.w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				h1.push({-dist[v], v});
			}
		}
	}

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		res += dist[pos[i]];
	}
	
	// std::cout << res << "\n";

	return res;
}

int main() {
	std::cin >> n >> p >> c;

	for (int i = 1; i <= n; i ++) {
		int x;
		std::cin >> x;
		pos[i] = x;
	}

	for (int i = 1; i <= c; i ++) {
		int a, b, e;
		
		std::cin >> a >> b >> e;

		g[a].push_back({b, e});
		g[b].push_back({a, e});
	}

	int ans = 0x3f3f3f3f;

	for (int i = 1; i <= p; i ++) {
		ans = std::min(ans, dijkstra(i));
	}

	std::cout << ans;
}