#include <iostream>
#include <queue>
#include <cstring>
#define ff first
#define ss second
typedef std::pair<int ,int> pii;
using i64 = long long;

const int N = 3e5 + 10;

int h[N], e[N], ne[N], w[N], idx;
int dist[N], n, m;
bool st[N];

struct edge {
	int v, w;
};

void add(int x, int y, int z) {
	ne[idx] = h[x], e[idx] = y, w[idx] = z, h[x] = idx ++;
}

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);

	std::priority_queue<pii, std::vector<pii>, std::greater<pii>> h1;

	dist[1] = 0;
	h1.push({0, s});

	while(h1.size()) {
		auto t = h1.top(); h1.pop();

		int u = t.ss;

		if(st[u]) continue;
		st[u] = true;

		for(int i = h[u]; ~i; i = ne[i]) {
			int j = e[i], d = w[i];

			if(dist[j] > dist[u] + d) {
				dist[j] = dist[u] + d;
				h1.push({dist[j], j});
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for(int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		add(x, y, z);
	}

	// s = 1, e = n;

	dijkstra(1);

	std::cout << (dist[n] == 0x3f3f3f3f?-1:dist[n]);
}