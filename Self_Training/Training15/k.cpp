#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

const int N = 500;

struct node {
	int d, w;
}dep[N][N];


struct node2 {
	int x, y;
}pre[N][N];

int n, m, t;

int sx, sy, ex, ey;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

char a[N][N];


int bfs() {
	std::queue<std::pair<int, int>> q1;

	dep[sx][sy].d = 0, dep[sx][sy].w = t;

	q1.push({sx, sy});

	while (q1.size()) {
		auto t = q1.front(); q1.pop();

		int x = t.ff, y = t.ss;

		// std::cout << x << " " << y << "\n";

		if (x == ex && y == ey) {
			return dep[ex][ey].d;
		}

		for(int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];

			if(tx >= 1 && tx <= n && ty >= 1 && ty <= m && dep[tx][ty].d == -1) {
				if(a[tx][ty] == '#') {
					if(dep[x][y].w) {
						q1.push({tx, ty});
						dep[tx][ty].d = dep[x][y].d;
						dep[tx][ty].w = dep[x][y].w - 1;

						pre[tx][ty].x = x, pre[tx][ty].y = y;
					}
				} else if(a[tx][ty] == '*' || a[tx][ty] == '+') {
					q1.push({tx, ty});
					
					dep[tx][ty].d = dep[x][y].d + 1;
					dep[tx][ty].w = dep[x][y].w;
					
					pre[tx][ty].x = x, pre[tx][ty].y = y;
				}
			}
		}
	}

	return -1;
}

int ans = 0;

void out(int x, int y) {
	if(x == sx && y == sy) {
		// printf("(%d, %d)", x, y);
		// ans ++;
		return;
	}

	out(pre[x][y].x, pre[x][y].y);

	// printf("->(%d, %d)", x, y);
	ans ++;
}

int main() {
	std::cin >> n >> m >> t;

	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			std::cin >> a[i][j];

			if(a[i][j] == '@') sx = i, sy = j;

			if(a[i][j] == '+') ex = i, ey = j;

			dep[i][j].d = -1;
		}
	}

	int k = bfs();

	if(k == -1) {
		std::cout << k;
		return 0;
	}

	out(ex, ey);

	// puts("");

	std::cout << ans << "\n";
}