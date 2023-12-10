#include <iostream>
#include <cstring>
#include <queue>

using i64 = long long;

const int maxn = 1e5 + 10;

int n, m;

int dist[maxn], cnt[maxn];

bool vis[maxn];

struct edge {int v, w;};

std::vector<edge> e[maxn];

bool spfa(int s) {
	memset(dist, 0x3f, sizeof dist);
	std::queue<int> q1;
	q1.push(s);
	dist[s] = 0, vis[s] = 1;
	while (q1.size()) {
		int u = q1.front(); q1.pop();

		vis[u] = false;

		for (auto ed: e[u]) {
			int v = ed.v, w = ed.w;
			if (dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				cnt[v] = cnt[u] + 1;
				if (cnt[v] >= n) return false;
				if (!vis[v]) q1.push(v), vis[v] = true;
			}
		}
	}

	return true;
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		e[x].push_back({y, z});
	}

	spfa(1);
	

	if (dist[n] > 0x3f3f3f3f / 2) puts("impossible");
	else std::cout << dist[n];
}