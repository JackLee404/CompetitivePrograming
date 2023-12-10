#include <iostream>
#include <queue>
#include <cstring>

using i64 = long long;

const int N = 110, M = 1e4 + 10;

int h[N], e[M], ne[M], w[M], idx;

int dist[N], level[N], m, n;

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

int spfa(int l, int r) {
	memset(st, false, sizeof st);
	memset(dist, 0x3f, sizeof dist);

	std::queue<int> q1;

	dist[0] = 0;
	q1.push(0);

	while (q1.size()) {
		int t = q1.front(); q1.pop();

		st[t] = false;

		for (int i = h[t]; ~i; i = ne[i]) {
			int v = e[i];
			if (dist[v] > dist[t] + w[i] && (level[v] >= l && level[v] <= r)) {
				dist[v] = dist[t] + w[i];			
				q1.push(v);
				if (!st[v]) q1.push(v), st[v] = true;
			}
		}
	}

	return dist[1];
}

int main() {
	memset(h, -1, sizeof h);
	std::cin >> m >> n;

	for (int i = 1; i <= n; i ++) {
		int p, l, x;

		std::cin >> p >> l >> x;

		add(0, i, p);

		level[i] = l;	

		while (x --) {
			int a, b;

			std::cin >> a >> b;

			add(a, i, b);
		}	
	}

	int ans = 0x3f3f3f3f;

	for (int i = level[1] - m; i <= level[1]; i ++) {
		int l = i, r = i + m;

		ans = std::min(ans, spfa(l, r));
	}

	std::cout << ans;
}