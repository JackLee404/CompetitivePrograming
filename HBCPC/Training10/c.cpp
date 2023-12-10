#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
#define INF 0x3f3f3f3f;
using namespace std;
typedef pair<int, int> PII;

int n, m;

char a[210][210];

struct node {
	int len, tag;
}d1[210][210];

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

int sx, sy, ex, ey;

int bfs() {
	queue<PII> q1;
	q1.push(make_pair(ex, ey));
	q1.push(make_pair(sx, sy));
	for (int i = 0; i <= 200; i ++) {
		for (int j = 0; j <= 200; j ++) {
			d1[i][j].len = -1;
			d1[i][j].tag = -1;
		}
	}
	d1[ex][ey].len = 0, d1[ex][ey].tag = 2;
	d1[sx][sy].len = 0, d1[sx][sy].tag = 1;	
	while (q1.size()) {
		PII t = q1.front(); q1.pop();
		int x = t.first, y = t.second;
		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty] != '#') {
				if (d1[tx][ty].tag != -1 && d1[tx][ty].tag != d1[x][y].tag && a[tx][ty] == '@') {
					return d1[tx][ty].len + d1[x][y].len + 1;
				} else if (d1[tx][ty].tag == -1) {	
					d1[tx][ty].tag = d1[x][y].tag;
					d1[tx][ty].len = d1[x][y].len + 1;
					q1.push(make_pair(tx, ty));
				}
			}	
		}
	}
	return -1;
}

vector<PII> v1;

int main() {
	while (cin >> n >> m) {
		v1.clear();
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					v1.push_back(make_pair(i, j));
				} else if (a[i][j] == 'Y') {
					sx = i, sy = j;
				} else if (a[i][j] == 'M') {
					ex = i, ey = j;
				}
			}
		}
		int ans = bfs();
		cout << ans * 11 << endl;
	}
}