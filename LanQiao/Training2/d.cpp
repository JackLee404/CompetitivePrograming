#include <iostream>

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

char a[40][70];

bool vis[40][70];

int ans, n, m, cnt;

void dfs(int x, int y) {
	cnt ++;
	for(int i = 0; i <= 3; i ++) {
		int tx = x + dx[i], ty = y + dy[i];
		if(tx <= n && tx >= 1 && ty <= m && ty >= 1 && a[tx][ty] != '0' && !vis[tx][ty]) {
			vis[tx][ty] = true;
			dfs(tx, ty);
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

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(!vis[i][j] && a[i][j] != '0') {
				cnt = 0;
				vis[i][j] = true;
				dfs(i, j);
				ans = std::max(ans, cnt);
			} 
		}
	}

	std::cout << ans;
}