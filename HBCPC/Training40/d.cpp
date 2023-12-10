#include <bits/stdc++.h>

using i64 = long long;

const int N = 10;

int c1, c2, r1, r2;

int step[5], depth[N][N], depth2[N][N];
 
int sx, sy, d1, d2;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

bool st[N][N], st2[N][N];

std::vector<std::pair<int, int>> v1;

int cmp(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		return y1 - y2;
	} else return x1 - x2;
}

struct node {
	int x1, y1, x2, y2;

	bool operator<(const node t) const {
		if (!cmp(x1, y1, t.x1, t.y1)) {
			return cmp(x2, y2, t.x2, t.y2) < 0;
		} else {
			return cmp(x1, y1, t.x1, t.y1) < 0;
		}
	}

	void out() {
		std::cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
	}
};

std::vector<node> ans;

void color(int c1, int c2, int r1, int r2, bool st[N][N]) {
	for (int i = 1; i <= 5; i ++) {
		st[i][c1] = st[i][c2] = true;
		st[r1][i] = st[r2][i] = true;
	}
}

void bfs(int x, int y, int depth[N][N]) {
	std::queue<std::pair<int, int>> q1, q2;

	q1.push({x, y});

	depth[x][y] = 0;

	while (q1.size()) {
		auto t = q1.front(); q1.pop();

		if (depth[t.first][t.second] == d1 && !st2[t.first][t.second]) v1.push_back({t.first, t.second});

		// std::cout << depth[x][y] << "\n";

		for (int i = 0; i <= 3; i ++) {
			int tx = t.first + dx[i], ty = t.second + dy[i];

			if (tx < 1 || ty < 1 || tx > 5 || ty > 5 || depth[tx][ty] != -1) continue;

			depth[tx][ty] = depth[t.first][t.second] + 1;

			q1.push({tx, ty});
		}
	}

	

	for (int i = 1; i <= 5; i ++) {
		for (int j = 1; j <= 5; j ++) {
			if (!st2[i][j]) {

			}
		}
	}
}

int main() {
	std::cin >> c1 >> c2 >> r1 >> r2;

	for (int i = 1; i <= 4; i ++) std::cin >> step[i];

	std::cin >> sx >> sy >> d1 >> d2;

	// r2 += step[4], r1 += step[3];

	color(c1, c2, r1 - step[3], r2 + step[4], st);

	color(c1 + step[1], c2 - step[2], r1 - step[3], r2 + step[4], st2);

	// std::cout << st[2][2] << "\n";

	memset(depth2, -1, sizeof depth2);

	bfs(sx, sy, depth2);

	for (int i = 1; i <= 5; i ++) {
		for (int j = 1; j <= 5; j ++) {
			if (!st[i][j]) {
				v1.clear();
				memset(depth, -1, sizeof depth);	
				bfs(i, j, depth);

				// std::cout << v1.size() << "\n";

				for (auto &t: v1) {
					if (depth2[t.first][t.second] == d2) {
						ans.push_back({i, j, t.first, t.second});
					}
				}
			}
		}
	}

	std::sort(ans.begin(), ans.end());

	for (auto x: ans) {
		x.out();
	}
}