#include <bits/stdc++.h>

using i64 = long long;

const int N = 51, M = 5510;

int n, m1, m2;

int h[N], e[M], w[M], ne[M], idx;

int dist[N], q[N], cnt[N];

bool st[N];

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

bool spfa() {
	int hh = 0, tt = 0;

	memset(dist, 0, sizeof dist);
	memset(st, 0, sizeof st);
	memset(cnt, 0, sizeof cnt);

	for (int i = 1; i <= n; i ++) {
		q[tt ++] = i;
		st[i] = true;
	}

	while (hh != tt) {
		int t = q[hh ++];
		if (hh == N) hh = 0;
		
		st[t] = false;

		for (int i = h[t]; ~i; i = ne[i]) {
			int v = e[i];
			if (dist[v] > dist[t] + w[i]) {
				dist[v] = dist[t] + w[i];
				cnt[v] = cnt[t] + 1;

				if (cnt[v] >= n) return true;	

				if (!st[v]) {
					q[tt ++] = v;
					if (tt == N) tt = 0;
					st[v] = true;
				}
			}
		}
	}

	return false;
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		memset(h, -1, sizeof h);
		idx = 0;
		
		std::cin >> n >> m1 >> m2;

		while (m1 --) {
			int a, b, c;

			std::cin >> a >> b >> c;

			add(a, b, c), add(b, a, c);
		}

		while (m2 --) {
			int a, b, c;

			std::cin >> a >> b >> c;

			add(a, b, -c);
		}

		puts(spfa()?"YES":"NO");
	}
}