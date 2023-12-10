#include <bits/stdc++.h>

using i64 = long long;

int dx[] = {0, -1, 0, 1}, dy[] = {-1, 0, 1, 0};

const int N = 20;

bool vis[N][N];
int n, m, sx, sy, ex, ey;
int a[N][N];

bool ok = false;

std::vector<std::pair<int, int>> path;

void dfs(int x, int y) {
	for(int i = 0; i <= 3; i ++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty] && a[tx][ty]) {
			if(tx == ex && ty == ey) {
				for(auto t: path) {
					printf("(%d,%d)->", t.first, t.second);
				}
				printf("(%d,%d)\n", ex, ey);
				ok = true;
				continue;
			}
			vis[tx][ty] = true;
			path.push_back({tx, ty});
			dfs(tx, ty);
			path.pop_back();
			vis[tx][ty] = false;
		}
	}
}



int main() {
	
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
		}
	}

	std::cin >> sx >> sy >> ex >> ey;

	path.push_back({sx, sy});
	vis[sx][sy] = true;
	dfs(sx, sy);

	if(!ok) {
		std::cout << -1;
	}
}