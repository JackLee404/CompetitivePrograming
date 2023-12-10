#include <iostream>
#include <deque>
#include <cstring>
#define ff first
#define ss second

using i64 = long long;

int r, c, dist[600][600];

char a[600][600];

int dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1};
int ix[] = {0, 0, 1, 1}, iy[] = {0, 1, 1, 0};

bool st[600][600];

/*
	考虑每次交换边权为1， 那么问题转化为从(1, 1) 到 (n, m) 的最短路

	因为边权只有0和1，所以我们可以考虑双端队列优化的dijkstra

	基本原理为， 将堆 改为 双端队列，插入时如果边权为1，那么把更新的点插入到队尾， 如果边权为0把更新的点插入到队头

	保证了每次出堆的都是离源点最近的点
*/

int bfs() {
	memset(dist, 0x3f, sizeof dist);
	memset(st, false, sizeof st);

	std::deque<std::pair<int, int>> q1;

	q1.push_front({0, 0});

	dist[0][0] = 0;

	while (q1.size()) {
		auto t = q1.front(); q1.pop_front();

		int x = t.ff, y = t.ss;

		if (st[x][y])
			continue;

		st[x][y] = true;

		char g[5] = "\\/\\/";
	
		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];

			if (tx < 0 || ty < 0 || tx > r || ty > c) continue;

			int gx = x + ix[i], gy = y + iy[i];

			int v = !(a[gx][gy] == g[i]);

			if (dist[tx][ty] > dist[x][y] + v) {
				dist[tx][ty] = dist[x][y] + v;
				if (v) {
					q1.push_back({tx, ty});
				} else {
					q1.push_front({tx, ty});
				}
			}
		}
	}

	return dist[r][c] == 0x3f3f3f3f?-1:dist[r][c];
}

void solve() {
	std::cin >> r >> c; 

	for (int i = 1; i <= r; i ++) {
		for (int j = 1; j <= c; j ++) {
			std::cin >> a[i][j];
		}
	}

	if (r + c & 1) {
		puts("NO SOLUTION");
	} else {
		int k = bfs();

		if (k == -1) {
			puts("NO SOLUTION");
		} else std::cout << k << "\n";
	}
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}