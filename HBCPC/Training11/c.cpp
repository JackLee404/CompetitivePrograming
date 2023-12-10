#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;


char a[15][15][3];

int n, m, t;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

int d[15][15][3];

bool flag, st[15][15][3];

struct tuples {
	int x, y, z;
};



void bfs() {
	queue<tuples> q1;
	tuples start = {1, 1, 1};
	memset(d, -1, sizeof d);
	memset(st, 0, sizeof st);
	d[1][1][1] = 0;
	q1.push(start);
	while (q1.size()) {
		tuples t1 = q1.front(); q1.pop();
		int x = t1.x, y = t1.y, z = t1.z;
		tuples next;

		if (a[x][y][z] == 'P') {
			if (d[x][y][z] <= t) {
				flag = true;
			}
			return;
		}

		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && a[tx][ty][z] != '*' && !st[tx][ty][z]) {
				st[tx][ty][z] = true;
				if(a[tx][ty][z] == '#') {
					int tz;
					if (z == 1) tz = 2;
					else tz = 1;
					if (a[tx][ty][tz] != '*' && a[tx][ty][tz] != '#' && d[tx][ty][tz] == -1) {
						next.x = tx, next.y = ty, next.z = tz;
						d[tx][ty][tz] = d[x][y][z] + 1;
						st[tx][ty][tz] = true;
						q1.push(next);
					}
					continue;
				}
				d[tx][ty][z] = d[x][y][z] + 1;
				next.x = tx, next.y = ty, next.z = z;
				q1.push(next);
			}
		}
	}
}

int main() {
	int _; 
	cin >> _;
	while (_ --) {
		memset(a, 0, sizeof a);
		flag = false;
		cin >> n >> m >> t;
		for (int z = 1; z <= 2; z ++) {
			for (int i = 1; i <= n; i ++) {
				for (int j = 1; j <= m; j ++) {
					cin >> a[i][j][z];
				}
			}
		}
		bfs();
		puts(flag?"YES":"NO");
	}
}