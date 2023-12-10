#include <iostream>
#include <queue>
#include <cstring>

using i64 = long long;

const int N = 2e3 + 10, M = 2e5 + 10;

int n, m, k, t, w[N], dist[N];

int h[N], e[M], ne[M], target[M], idx;

int f[N][N];

std::queue<int> q1;

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, target[idx] = c, e[idx ++] = b;
}


void spfa() {
	while (q1.size()) {
		int x = q1.front(); q1.pop();
		st[x] = false;

		// std::cout << x << "\n";

		for (int i = h[x]; ~i; i = ne[i]) {
			int y = e[i], z = target[i];
			if (dist[z] > std::max(dist[x], dist[y]) + std::max(w[x], w[y])) {
				dist[z] = std::max(dist[x], dist[y]) + std::max(w[x], w[y]);
				if (!st[z]) {
					st[z] = true;
					q1.push(z);
				}
			}
		}
	}
}


int main() {
	memset(dist, 0x3f, sizeof dist);
	memset(h, -1, sizeof h);

	std::cin >> n >> m >> k >> t;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	for (int i = 1; i <= m; i ++) {
		int x;
		std::cin >> x;

		dist[x] = 0;
		q1.push(x);
		st[x] = true;
	}

	for (int i = 1; i <= k; i ++) {
		int a, b, c;
		
		std::cin >> a >> b >> c;

		add(a, b, c);
		add(b, a, c);
	}

	spfa();

	std::cout << dist[t];
}