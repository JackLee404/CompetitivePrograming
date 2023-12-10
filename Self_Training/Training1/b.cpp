#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int N = 1e3 + 10;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

struct node {
	int jt = 0, ft = 0;
}d[N][N];

int n, m, sx, sy, ans;

char a[N][N];

queue<pair<int, int>> q2;

void bfs() {
	while(q2.size()) {
		pair<int, int> t = q2.front(); q2.pop();
		for (int i = 0; i <= 3; i ++) {
			int x = t.first + dx[i], y = t.second + dy[i];
			if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#' && d[x][y].ft == -1) {
				d[x][y].ft = d[t.first][t.second].ft + 1;
				q2.push({x, y});
			}
		}
	}
}


void bfs2() {
	queue<pair<int, int>> q1;
	q1.push({sx, sy});
	d[sx][sy].jt = 1;
	while(q1.size()) {
		pair<int, int> t = q1.front(); q1.pop();
		if(t.first == 1 || t.second == 1 || t.first == n || t.second == m) {
			ans = min(ans, d[t.first][t.second].jt);
			return;
		}
		for (int i = 0; i <= 3; i ++) {
			int x = t.first + dx[i], y = t.second + dy[i];
			if(x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#' && d[x][y].jt == -1) {
				d[x][y].jt = d[t.first][t.second].jt + 1;
				if(d[x][y].jt < d[x][y].ft || (d[x][y].ft == -1))
					q1.push({x, y});
			}
		}
	}
}

int main() {
	int _; cin >> _;
	while (_ --) {
		cin >> n >> m;
		while(q2.size()) q2.pop();
		memset(d, -1, sizeof d);
		ans = 0x3f3f3f3f;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				cin >> a[i][j];
				if (a[i][j] == 'J') sx = i, sy = j;
				else if (a[i][j] == 'F') {
					d[i][j].ft = 1;
					q2.push({i, j});
				}
 			}
		}
		bfs();
		bfs2();
		if (ans == 0x3f3f3f3f) cout << "IMPOSSIBLE";
		else cout << ans;
		cout <<"\n";
	}
}