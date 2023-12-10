#include <bits/stdc++.h>

using i64 = long long;

const int M = 500;

int n, m, t;

int sx, sy, ex, ey;

int ans;

bool nvis[M][M], been_vis[M][M];

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

void dfs(int x, int y) {
	if(x == ex && y == ey) {
		ans ++;
		return;
	}

	for(int i = 0; i <= 3; i ++) {
		int tx = x + dx[i], ty = y + dy[i];

		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !nvis[tx][ty] && !been_vis[tx][ty]) {
			been_vis[tx][ty] = true;
			dfs(tx, ty);
			been_vis[tx][ty] = false;
		}
	}
}

/*
	DFS
*/

void solve() {
	std::cin >> n >> m >> t;

	std::cin >> sx >> sy >> ex >> ey;

	been_vis[sx][sy] = true;

	for(int i = 1; i <= t; i ++) {
		int x, y;
		std::cin >> x >> y;
		nvis[x][y] = true;
	}

	dfs(sx, sy);

	std::cout << ans;
}

int main() {
	int _;
	// std::cin >> _;
	_ = 1;
	while(_ --) {
		solve();
	}
}