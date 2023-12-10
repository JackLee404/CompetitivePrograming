#include <bits/stdc++.h>


using i64 = long long;

const int N = 5e5 + 10;

int n, m, depth[N], fa[N][18], res[N], d2[N];

std::vector<int> G[N], G2[N];

void bfs(int s) {
	memset(depth, 0x3f, sizeof depth);

	depth[0] = 0, depth[s] = 1;

	std::queue<int> q1;

	q1.push(s);

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		for (auto v: G[u]) {
			if (depth[v] > depth[u] + 1) {
				q1.push(v);
				depth[v] = depth[u] + 1;
				fa[v][0] = u;

				for (int k = 1; k <= 17; k ++) {
					fa[v][k] = fa[fa[v][k - 1]][k - 1];
				}
			}
		}
	}
}

int lca(int a, int b, int d) {
	if (depth[a] < depth[b]) std::swap(a, b);

	std::vector<int> v1;

	v1.push_back(a), v1.push_back(b);

	for (int k = 17; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			a = fa[a][k];
			v1.push_back(a);
		}
	}

	if (a == b) return a;

	for (int k = 17; k >= 0; k --) {
		if (fa[a][k] != fa[b][k]) {
			a = fa[a][k];
			b = fa[b][k];
			v1.push_back(a), v1.push_back(b);
		}
	}

	v1.push_back(fa[a][0]);

	for (auto &v: v1) {
		res[v] = std::min(res[v], d);
	}

	return fa[a][0];
}


void bfs2(int s) {
	std::queue<int> q1;

	memset(d2, 0x3f, sizeof d2);

	q1.push(s);

	d2[s] = 1;

	while (q1.size()) {
		int u = q1.front(); q1.pop();
		
		for (auto &v: G2[u]) {
			if (d2[v] <= d2[u] + 1) continue;

			lca(u, v, d2[u]);

			d2[v] = d2[u] + 1;

			q1.push(v);
		}
	}
}

void solve() {
	memset(res, 0x3f, sizeof res);

	std::cin >> n >> m;

	for (int i = 1; i <= n - 1; i ++) {
		int x; std::cin >> x;

		G[x].push_back(i + 1), G[i + 1].push_back(x);
	}

	bfs(1);


	for (int i = 1; i <= m; i ++) {
		int x, y; std::cin >> x >> y;
		
		G2[x].push_back(y), G2[y].push_back(x);
	}

	bfs2(1);

	for (int i = 1; i <= n - 1; i ++) {
		std::cout << (res[i + 1] == 0x3f3f3f3f? -1: res[i + 1]) << " \n"[i == n - 1];
	}
}

int main() {
	int _;

	// std::cin >> _;

	_ = 1;

	while (_ --) {
		solve();
	}
}