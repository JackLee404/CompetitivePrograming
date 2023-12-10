#include <bits/stdc++.h>
using i64 = long long;

const int N = 600, M = 2e4 + 10, INF = 0x3f3f3f3f;

struct Edge {
	int a, b;

	i64 w;

	bool used;

	void input() {
		std::cin >> a >> b >> w;
	};

	void out() {
		std::cout << a << " " << b << " " << w << "\n";
	};

	bool operator<(const Edge &t) const {
		return w < t.w;
	};
} edge[N];

int n, m;

int h[N], ne[M], e[M], idx;

i64 w[M];

int fa[N][17], d1[N][17], d2[N][17];

int depth[N], p[N], q[N];
 
bool st[N];

void add(int a, int b, i64 c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

i64 kruskal() {
	std::sort(edge + 1, edge + 1 + m);

	i64 res = 0;

	for (int i = 1; i <= m; i ++) {
		int a = edge[i].a, b = edge[i].b;

		i64 w = edge[i].w;

		int fa = find(a), fb = find(b);

		if (fa != fb) {
			edge[i].used = true;
			// puts("used:");
			// edge[i].out();
			p[fa] = fb;
			res += w;
		}
	}

	return res;
}

void build() {
	for (int i = 1; i <= m; i ++) {
		Edge &t = edge[i];
		if (edge[i].used) {
			add(t.a, t.b, t.w);
			add(t.b, t.a, t.w);
		}
	}
}

void dfs(int u) {
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (st[v] || v == u) continue;

		st[v] = true;
		
		if (depth[v] > depth[u]) {
			depth[v] = depth[u] + 1;

			fa[v][0] = u;

			d1[v][0] = w[i], d2[v][0] = -INF;
			
			for (int k = 1; k <= 16; k ++) {
				int anc = fa[v][k - 1];

				fa[v][k] = fa[anc][k - 1];

				i64 distance[4] = {d1[v][k - 1], d2[v][k - 1], d1[anc][k - 1], d2[anc][k - 1]};

				d1[v][k] = d2[v][k] = -INF;

				for (int u = 0; u < 4; u ++) {
					i64 d = distance[u];
					
					if (d > d1[v][k]) d2[v][k] = d1[v][k], d1[v][k] = d;
					else if (d != d1[v][k] && d > d2[v][k]) d2[v][k] = d;
				}
			}
		}

		dfs(v);
	}
}


i64 lca(int a, int b, i64 w) {
	static i64 distance[N * 2];

	int cnt = 0;

	if (depth[a] < depth[b]) std::swap(a, b);

	for (int k = 16; k >= 0; k --) {
		if (depth[fa[a][k]] >= depth[b]) {
			distance[++ cnt] = d1[a][k];
			distance[++ cnt] = d2[a][k]; 
			
			a = fa[a][k];
		}
	}

	if (a != b) {
		for (int k = 16; k >= 0; k --) {
			if (fa[a][k] != fa[b][k]) {
				distance[++ cnt] = d1[a][k];
				distance[++ cnt] = d2[a][k];
				distance[++ cnt] = d1[b][k];
				distance[++ cnt] = d2[b][k];

				a = fa[a][k], b = fa[b][k];
			}
		}
		distance[++ cnt] = d1[a][0];
		distance[++ cnt] = d1[b][0];
	}

	i64 dist1 = -INF, dist2 = -INF;

	for (int i = 1; i <= cnt; i ++) {
		i64 d = distance[i];
		
		if (d > dist1) dist2 = dist1, dist1 = d;
		else if (d != dist1 && d > dist2) dist2 = d;
	}
	
	if (w > dist1) return w - dist1;
	if (w > dist2) return w - dist2;

	return INF;
}

int main() {
	memset(h, -1, sizeof h);

	memset(depth, 0x3f, sizeof depth);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) p[i] = i;

	for (int i = 1; i <= m; i ++) {
		edge[i].input();
	}

	i64 sum = kruskal();

	build();

	depth[0] = 0;
	depth[1] = 1;
	dfs(1);

	i64 ans = INF;

	for (int i = 1; i <= m; i ++) {
		if (!edge[i].used) {
			int a = edge[i].a, b = edge[i].b;

			i64 w = edge[i].w;

			ans = std::min(ans, sum + lca(a, b, w));
		}	
	}

	std::cout << ans;
}