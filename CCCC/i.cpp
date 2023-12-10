#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e3 + 100;

int n, m;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

char a[N][N];

bool st[N][N];

int ans1, ans2;

bool ok;

void dfs(int x, int y) {
	st[x][y] = true;
	
	if (a[x][y] != '0' && a[x][y] != '1') ok = true;
	
	for (int i = 0; i <= 3; i ++) {
		int tx = x + dx[i], ty = y + dy[i];
		
		if (tx < 1 || tx > n || ty < 1 || ty > m) continue;
		
		if (a[tx][ty] == '0') continue;
		
		if (!st[tx][ty]) {
			dfs(tx, ty);
		}
	}	
}


int main() {
	std::cin >> n >> m; getchar();
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
		}
	}
	
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (!st[i][j] && a[i][j] != '0') {
				ok = false;
				ans1 ++;
				
				dfs(i, j);
				ans2 += (int) ok;
			}
		}
	}	
	
	std::cout << ans1 << " " << ans2;
}