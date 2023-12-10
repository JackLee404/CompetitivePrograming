#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10;

struct node {
	int v, w;
};

int n, m, s1, e1;

int idx, ne[N], h[N], dist[N];

bool st[N];

node e[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = {b, c};
}

void dijkstra(int s1) {
	memset(dist, 0x3f, sizeof dist);		
	
	dist[s1] = 0;

	for (int i = 0; i < n - 1; i ++) {
		int t = -1;

		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		for (int j = h[t]; ~j; j = ne[j]) {
			int v = e[j].v, w = e[j].w;
			dist[v] = std::min(dist[v], dist[t] + w);
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m >> s1 >> e1;

	for (int i = 1; i <= m; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c);
		add(b, a, c);
	}

	dijkstra(s1);

	std::cout << dist[e1];
}