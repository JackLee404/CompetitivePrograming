#include <iostream>
#include <queue>
#include <cstring>
#include <utility>
#define f first
#define s second
#define INF 0x3f3f3f3f
#define siz(v) ((int) v.size())
#define judge(x, y) (x >= 1 && x <= n && y >= 1 && y <= m)
#define mahaton(x1, y1, x2, y2) (abs(x1 - x2) + abs(y1 - y2))
using namespace std;

typedef pair<int, int> PII ;


int n, m, r1, r2;

int sx, sy, ex, ey;

int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

int d1[1010][1010], d2[1010][1010];

char a[1010][1010];

vector<PII> crux;

// 扩展猫咪
void bfs() {
	queue<PII> q1;
	q1.push({sx, sy});
	memset(d1, -1, sizeof d1);
	d1[sx][sy] = 0;
	while(q1.size()) {
		auto t = q1.front(); q1.pop();

		int x = t.f, y = t.s;

		// cout << x << " " << y << endl;

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (judge(tx, ty) && d1[tx][ty] == -1 && mahaton(sx, sy, tx, ty) <= r2) {
				d1[tx][ty] = d1[x][y] + 1;
				q1.push({tx, ty});
			}
		}
	}	
}

// 主人步数扩展
void bfs2() {
	queue<PII> q1;
	q1.push({ex, ey});
	memset(d2, -1, sizeof d2);
	d2[ex][ey] = 0;
	while(q1.size()) {
		auto t = q1.front(); q1.pop();

		int x = t.f, y = t.s;

		

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (judge(tx, ty) && a[tx][ty] != '*' && d2[tx][ty] == -1 && mahaton(ex, ey, tx, ty) <= r1) {
				d2[tx][ty] = d2[x][y] + 1;
				q1.push({tx, ty});
				if (d1[tx][ty] != -1) {
					crux.push_back({tx, ty});
				}
			}
		}

	}
}



// 重新拓展 不考虑曼哈顿距离
void bfs3() {
	queue<PII> q1;
	q1.push({sx, sy});
	memset(d1, -1, sizeof d1);
	d1[sx][sy] = 0;
	while(q1.size()) {
		auto t = q1.front(); q1.pop();

		int x = t.f, y = t.s;

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (judge(tx, ty) && a[tx][ty] != '*' && d1[tx][ty] == -1) {
				d1[tx][ty] = d1[x][y] + 1;
				q1.push({tx, ty});
			}
		}

	}	
}


int main() {
	cin >> n >> m >> r1 >> r2;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			cin >> a[i][j];
			if (a[i][j] == 'M')
				sx = i, sy = j;
			else if (a[i][j] == 'P')
				ex = i, ey = j;
		}
	}

	bfs();
	bfs2();

	int ans = INF;

	if (!siz(crux)) {
		cout << -1;
	} else {
		bfs3();
		for (auto& v: crux) {
            if (d1[v.f][v.s] != -1)
                ans = min(ans, d1[v.f][v.s] + d2[v.f][v.s]);
		}
		if (ans == INF) {
			cout << -1;
		} else {
			cout << ans;
		}
	}
}
