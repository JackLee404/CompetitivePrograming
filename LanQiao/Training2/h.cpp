#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 400;

int n, m;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

int a[N][N], f[N][N];

int ans;

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int dfs(int x, int y) {
	if(f[x][y] != -1) return f[x][y];

	f[x][y] = 1;

	for(int i = 0; i <= 3; i ++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] < a[x][y]) {
			f[x][y] = std::max(f[x][y], dfs(tx, ty) + 1);
		}
	}

	return f[x][y];
}

int main() {
	memset(f, -1, sizeof f);

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(f[i][j] == -1)
				dfs(i, j);
			ans = std::max(f[i][j], ans);
		}
	}

	std::cout << ans;
}