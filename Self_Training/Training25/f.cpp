#include <iostream>
#include <queue>
#include <cstring>

using i64 = long long;

const int N = 1100, M = 1e4 + 10;

int n, m;

int h[N], e[M], ne[M], t[M], f[N], idx;

double dist[N];

int cnt[N];

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, t[idx ++] = c;
}
	
bool spfa(double mid) {
	memset(dist, 0, sizeof dist);
	memset(cnt, 0, sizeof cnt);
	memset(st, 0, sizeof st);

	std::queue<int> q1;

	for (int i = 1; i <= n; i ++) {
		q1.push(i);
		st[i] = true;
	}

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		st[u] = false;

		// std::cout << u << "\n";

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			if (dist[v] < dist[u] + (f[u] - t[i] * mid)) {
				dist[v] = dist[u] + (f[u] - t[i] * mid);
				cnt[v] = cnt[u] + 1;
				
				if (cnt[v] >= n) {
					return true;
				}
				
				if (!st[v]) {
					q1.push(v);
					st[v] = true;
				}
			}
		}
	}

	return false;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) std::cin >> f[i];

	for (int i = 1; i <= m; i ++) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c);
		// add(b, a, c);
	}

	// for (int i = 1; i <= n; i ++) {
	// 	add(0, i, 0);
	// }

	double l = 0, r = 1e6;

	while (r - l > 1e-4) {
		double mid = (l + r) / 2;

		if (spfa(mid)) l = mid;
		else r = mid;
	}

	printf("%.2lf", l);
}