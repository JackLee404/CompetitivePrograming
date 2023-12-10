#include <bits/stdc++.h>

using i64 = long long;

const int N = 4e4 + 10, M = N * 2;

int n;

int h[N], ne[M], e[M], idx;

int fa[N][16], depth[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs(int s) {
	memset(depth, 0x3f, sizeof depth);
	std::queue<int> q1;
	depth[0] = 0;
	depth[s] = 1;
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
	memset(h, -1, sizeof h);

	std::cin >> n;

	int root = 1;

	for (int i = 1; i <= n; i ++) {
		int a, b;

		std::cin >> a >> b;

		if (b == -1) {
			root = a;
			continue;
		}

		add(a, b), add(b, a);
	}

	bfs(root);

	int m;

	std::cin >> m;

	while(m --) {
		int a, b;

		std::cin >> a >> b;

		int k = lca(a, b);

		if (k == a) {
			puts("1");
		} else if (k == b) {
			puts("2");
		} else puts("0");
	}
}