#include <iostream>
#include <vector>
#include <cstring>
#define sz(x) (int)x.size()

// using i64 = long long;

const int N = 500, M = 2 * N ;

int h[N], e[M], ne[M], idx;

std::vector<int> level[N];

int cnt[N], c[M];

int n, m, ans;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
	ne[idx] = h[b], h[b] = idx, e[idx ++] = a;
}

int dfs_level(int u, int depth, int father) {
	cnt[u] = 1;

	for(int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if(j == father) continue;

		cnt[u] += dfs_level(j, depth + 1, u);
		level[depth].push_back(i);
	}

	return cnt[u];
}

void dfs_draw(int j, int color) {
	c[j] = color;

	for(int i = h[e[j]]; ~i; i = ne[i]) {
		if(i != (j ^ 1))
			dfs_draw(i, color);
	}
}

void dfs(int u, int s) {
	ans = std::min(ans, s);

	for(int i = 0; i < sz(level[u]); i ++) {
		int j = level[u][i];

		if(!c[j]) {
			dfs_draw(j, 1);
			dfs(u + 1, s - cnt[e[j]]);
			dfs_draw(j, 0);
		}
	}
}

int main() {
	std::cin >> n >> m;

	memset(h, -1, sizeof h);

	ans = n;

	for(int i = 0; i < m; i ++) {
		int a, b;
		std::cin >> a >> b;
		add(a, b);
	}

	dfs_level(1, 0, -1);

	dfs(0, n);

	std::cout << ans;
}