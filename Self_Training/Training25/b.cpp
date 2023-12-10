#include <bits/stdc++.h>

using i64 = long long;

const int N = 4e4 + 10, M = N * 2;

int n, m;

int h[N], e[M], ne[M], idx;

int depth[N], fa[N][16];

int q[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs(int s) {
	memset(depth, 0x3f, sizeof depth);
	depth[0] = 0, depth[s] = 1;
	std::queue<int> q1;
	q1.push(s);

	while (q1.size()) {
		int t = q1.front(); q1.pop();

		for (int i = h[t]; ~i; i = ne[i]) {
			int v = e[i];
			if (depth[v] > depth[t] + 1) {
				q1.push(v);
				depth[v] = depth[t] + 1;	
				fa[v][0] = t;
				for (int k = 1; k <= 15; k ++) {
					fa[v][k] = fa[fa[v][k - 1]][k - 1];
				}
			}
		}
	}
}

int lca(int a, int b) {
	if (depth[a] < depth[b]) std::swap(a, b);

	for (int k = 15; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
		}
	}

	if (a == b) return a;

	for (int k = 15; k >= 0; k --) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
		}
	}

	return fa[a][0];
}

int main() {
	std::cin >> n;

	int root = 0;

	memset(h, -1, sizeof h);

	for (int i = 0; i < n; i ++) {
		int a, b;

		std::cin >> a >> b;

		if (b == -1) root = a;
		else add(a, b), add(b, a);
	}

	bfs(root);

	std::cin >> m;

	while (m --) {
		int a, b;

		std::cin >> a >> b;

		int k = lca(a, b);

		if (k == a) {
			std::cout << 1;
		} else if (k == b) {
			std::cout << 2;
		} else std::cout << 0;

		puts("");
	}
}