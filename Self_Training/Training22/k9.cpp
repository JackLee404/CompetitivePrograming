#include <iostream>
#include <cstring>
#include <queue>

using i64 = long long;

const int N = 1e5 + 10, M = 1e6 + 10;

int n, m;

int hs[N], ht[N], e[M], ne[M], w[N], idx;

int dmin[N], dmax[N];

bool st[N];

void add(int h[], int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void spfa(int h[], int dist[], int type) {
	std::queue<int> q1;

	if (type) {
		memset(dist, -0x3f, sizeof dmax);
		dist[n] = w[n];
		q1.push(n);
	} else {
		memset(dist, 0x3f, sizeof dmin);
		dist[1] = w[1];
		q1.push(1);
	}

	while (q1.size()) {
		int t = q1.front(); q1.pop();
		
		st[t] = false;

		// std::cout << t << "\n";

		for (int i = h[t]; ~i; i = ne[i]) {
			int j = e[i];

			if (type == 1 && dist[j] < std::max(w[j], dist[t])) {
				dist[j] = std::max(w[j], dist[t]);
				q1.push(j);
				if (!st[j]) st[j] = true;
			} else if (type == 0 && dist[j] > std::min(w[j], dist[t])) {
				dist[j] = std::min(w[j], dist[t]);
				q1.push(j);
				if (!st[j]) st[j] = true;
			}
		}
	}
}

int main() {
	memset(hs, -1, sizeof hs);
	memset(ht, -1, sizeof ht);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) std::cin >> w[i];

	for (int i = 1; i <= m; i ++) {
		int x, y, z;

		std::cin >> x >> y >> z;

		add(hs, x, y), add(ht, y, x);

		if (z == 2) add(hs, y, x), add(ht, x, y);
	}

	spfa(hs, dmin, 0);

	spfa(ht, dmax, 1);

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		res = std::max(res, dmax[i] - dmin[i]);
	}

	std::cout << res;
}