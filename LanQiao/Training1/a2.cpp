#include <iostream>

// using i64 = long long;

const int N = 15, M = 130;

int n, m, p, ans, tot;
bool st[N][M];

int dx[] = {0, 1}, dy[] = {1, 0};

void dfs(int x, int y, int num) {
	if(x == n && y == m + 1) {
		if(num == tot) {
			ans ++, ans %= 10007;
		}
		return;
	}
	if(y == m + 1) dfs(x + 1, 1, num);
	else if(!st[x][y]) {
		for(int i = 0; i <= 1; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && !st[tx][ty]) {
				st[tx][ty] = st[x][y] = 1;
				dfs(x, y + 1, num + 2);
				st[tx][ty] = st[x][y] = 0;
			}
		}
	} else dfs(x, y + 1, num);
}

int main() {
	std::cin >> n >> m >> p;

	tot = n * m - p;

	for(int i = 1; i <= p; i ++) {
		int x, y;
		std::cin >> x >> y;
		st[x][y] = true;
	}

	dfs(1, 1, 0);

	std::cout << ans;
}