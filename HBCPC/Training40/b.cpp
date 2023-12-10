#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e3 + 10, M = N * 2;

int n;

int h[N], ne[M], e[M], w[N], idx;

int d[N][N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs(int root, int d1[N]) {
	std::queue<int> q1;

	q1.push(root);

	d1[root] = 0;

	while (q1.size()) {
		int t = q1.front(); q1.pop();

		for (int i = h[t]; ~i; i = ne[i]) {
			int v = e[i];

			if (d1[v] == -1) {
				d1[v] = d1[t] + 1;
				q1.push(v);
			}
		}
	}
}


int main() {
	std::ios::sync_with_stdio(false);

	memset(h, -1, sizeof h);

	std::cin >> n;

	for (int i = 1; i < n; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b), add(b, a);
	}

	for (int i = 1; i <= n; i ++) std::cin >> w[i];

	// memset(d, -1, sizeof d);

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) d[i][j] = -1;
		bfs(i, d[i]);
	}

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			for (int k = j + 1; k <= n; k ++) {
				if (d[i][j] == d[j][k] && d[i][j] == d[i][k]) {
					if (w[i] != w[j] && w[i] != w[k] && w[j] != w[k]) {
						ans ++;
					}
				}
			}
		}
	}

	std::cout << ans;
}