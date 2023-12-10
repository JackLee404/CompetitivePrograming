#include <iostream>
#include <vector>
#include <cstring>

using i64 = long long;

const int N = 1e5 + 10;

int n, m;

struct edge {
	i64 b, c, d;	
};

std::vector<edge> g[N];

i64 dist[N], dist2[N];

int cnt[N];

bool st[N];

void dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);

	dist[s] = 0;

	for (int i = 0; i < n - 1; i ++) {
		int t = -1;

		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist[t] > dist[j]))
				t = j;


		st[t] = true;

		for (auto x: g[t]) {
			int b = x.b, c = x.c, d = x.d;

			if (dist[b] > dist[t] + c && !d) {
				dist[b] = dist[t] + c;
			}
		}
	}
}

void dijkstra2(int s) {
	memset(dist2, 0x3f, sizeof dist2);
	memset(st, false, sizeof st);

	dist2[s] = 0;

	for (int i = 0; i < n - 1; i ++) {
		int t = -1;

		for (int j = 1; j <= n; j ++)
			if (!st[j] && (t == -1 || dist2[t] > dist2[j]))
				t = j;


		st[t] = true;

		for (auto x: g[t]) {
			int b = x.b, c = x.c, d = x.d;

			if (dist2[b] > dist2[t] + c && (cnt[t] + (int) (d > 0)) <= 2) {
				dist2[b] = dist2[t] + c;
				cnt[b] = cnt[t] + (int) (d > 0);
			} else if (dist2[b] == dist2[t] + c) {
				if (cnt[b] > cnt[t] + (int) (d > 0)) {
					cnt[b] = cnt[t] + (int) (d > 0);
				}
			}
		}
	}
}


int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int a, b, c, d;

		std::cin >> a >> b >> c >> d;

		g[a].push_back({b, c, d});
		g[b].push_back({a, c, d});
	}

	dijkstra(1);
	dijkstra2(1);

	std::cout << dist[n] - dist2[n];
}