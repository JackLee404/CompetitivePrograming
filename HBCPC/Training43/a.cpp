#include <bits/stdc++.h>

using i64 = long long;

const int N = 6e5 + 10, M = N * 2;

int h[N], e[M], ne[M], idx;

int n, m, d, depth[N];

bool st[N], st2[N];

int sx, ex;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

bool bfs() {
	memset(depth, -1, sizeof depth);

	std::queue<int> q1;

	q1.push(sx);

	depth[sx] = 0;

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		if (u == ex) return true;
		
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];		

			if (st[v] || depth[v] != -1) continue;

			depth[v] = depth[u] + 1;


			if (v == ex) return true;

			q1.push(v);
		}		
	}

	return false;
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n >> m >> d;

	for (int i = 1; i <= m; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b), add(b, a);
	}

	for (int i = 1; i <= d; i ++) {
		int c, q, cnt = 0;

		std::cin >> c >> q;

		st[c] = true;

		while (q --) {
			std::cin >> sx >> ex;

			if (st[sx] || st[ex]) {
				cnt ++;
				continue;
			}

			if (!bfs()) cnt ++;
		}

		std::cout << cnt << "\n";
	}
}