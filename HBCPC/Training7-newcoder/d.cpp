#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

const int N = 1e5 + 10;

int n, m, a[2010][2010], d[2010][2010];
int sx, sy, ex, ey;

struct node {
	int x, y, w;

	bool operator<(const node a) const {
		return this->w < a.w;
	}
};

void bfs() {
	priority_queue<node> q1;
	memset(d, -1, sizeof d);
	q1.push({sx, sy, 0});
	d[sx][sy] = 0;
	q1.push({sx, sy, 0});
	while (q1.size()) {
		auto t = q1.top(); q1.pop();
		if (t.x == ex && t.y == ey) {
			return;
		}
		for (int i = 0; i < 4; i ++) {
			int tx = t.x + dx[i], ty = t.y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] && d[tx][ty] == -1) {
				if (a[tx][ty] != -1)
					d[tx][ty] = d[t.x][t.y] + 1;
				else
					d[tx][ty] = d[t.x][t.y];
				q1.push({tx, ty, a[tx][ty]});
			}
		}
	}
}

int main() {
	cin >> n >> m;
	cin >> sx >> sy >> ex >> ey;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
		}
	}
	bfs();
	cout << d[ex][ey];
}