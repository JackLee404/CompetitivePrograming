#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int n, m;

int a[N][N], dep[N][N];

int dx[] = {0, 1, -1, 0}, dy[] = {1, 0, 0, -1};

std::queue<std::pair<int, int>> q1;

int bfs() {

	while (q1.size()) {
		auto t = q1.front(); q1.pop();

		int x = t.first, y = t.second;

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];

			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] == 1 && dep[tx][ty] == -1) {
				dep[tx][ty] = dep[x][y] + 1;
				q1.push({tx, ty});
			}
		}
	}

	int ans = -1;
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (a[i][j] == 1)
				ans = std::max(ans, dep[i][j]);
		}
	}

	return ans;
}

int main() {
	memset(dep, -1, sizeof dep);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];

			if (a[i][j] == 2) {
				q1.push({i, j});
				dep[i][j] = 0;
			}
		}
	}

	std::cout << bfs();
}