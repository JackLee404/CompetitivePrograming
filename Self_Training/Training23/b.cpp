#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <cstring>
#define ff first
#define ss second
using i64 = long long;
#define debug(x) std::cout << x << "\n"
int n, m, p, k, s;

const int N = 20, M = 400, P = 1 << 10 + 1;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

int calc(int x, int y) {
	return (x + 1) * 11 + y;
}

int key[N], door[M][M], dist[M][P];

bool st[M][P];

int bfs() {
	memset(dist, 0x3f, sizeof dist);

	std::deque<std::pair<int, int>> q1;

	q1.push_back({calc(1, 1), 0});

	dist[calc(1, 1)][0] = 0;

	while (q1.size()) {
		auto t = q1.front(); q1.pop_front();
		
		if (st[t.ff][t.ss]) continue;

		st[t.ff][t.ss] = true;

		int x = t.ff / 11 - 1, y = t.ff % 11;
		
		if (x == n && y == m) {
			return dist[t.ff][t.ss];
		}
	
		if (key[t.ff]) {
			int state = t.ss | key[t.ff];	

			if (dist[t.ff][state] > dist[t.ff][t.ss]) {
				dist[t.ff][state] = dist[t.ff][t.ss];
				q1.push_front({t.ff, state});
			}
		}

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];

			if (tx < 1 || tx > n || ty < 1 || ty > m) continue;

			int k = calc(tx, ty);

			if (door[t.ff][k] == -1) continue;


			if (door[t.ff][k] && !(t.ss >> door[t.ff][k] - 1 & 1)) {
				continue;
			}

			if (dist[k][t.ss] > dist[t.ff][t.ss] + 1) {
				dist[k][t.ss] = dist[t.ff][t.ss] + 1;
				q1.push_back({k, t.ss});
			}
		}
	}

	return -1;
}


int main() {
	std::cin >> n >> m >> p >> k;

	for (int i = 1; i <= k; i ++) {
		int x1, y1, x2, y2, c;

		std::cin >> x1 >> y1 >> x2 >> y2 >> c;

		if (!c) c = -1;

		int p1 = calc(x1, y1), p2 = calc(x2, y2);

		door[p1][p2] = door[p2][p1] = c;
	}

	std::cin >> s;

	for (int i = 1; i <= s; i ++) {
		int x, y, q;

		std::cin >> x >> y >> q;

		key[calc(x, y)] |= 1 << q - 1;
	}

	std::cout << bfs();
}