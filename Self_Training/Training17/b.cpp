#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10;

struct node {
	int v, w;
};

int n, m, dist[N], cnt[N];

bool st[N];

int idx, ne[N], h[N];

node e[N];


void add(int a, int b, int k) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = {b, k};
}

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(cnt, -0x3f, sizeof cnt);

	dist[s] = 0;
	cnt[s] = 1;

	for (int i = 0; i < n - 1; i ++) {
		int t = -1;

		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;

		st[t] = true;

		for (int j = h[t]; ~j; j = ne[j]) {
			int v = e[j].v, w = e[j].w;

			if (cnt[v] < cnt[t] + 1) {
				dist[v] = dist[t] + w;
				cnt[v] = cnt[t] + 1;
			} else if (cnt[v] == cnt[t] + 1 && dist[v] > dist[t] + w) {
				dist[v] = dist[t] + w;	
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;
		
		add(a, b, c);
		add(b, a, c);
	}

	dijkstra(1);

	int k = 1;

	for (int i = 1; i <= n; i ++) {
		if (cnt[i] == n && dist[i] < dist[k]) {
			k = i;
		}
		std::cout << cnt[i] << " " << dist[i] << "\n";
	}

	if (cnt[k] != n) {
		std::cout << -1;
	} else {
		std::cout << dist[k];
	}
}