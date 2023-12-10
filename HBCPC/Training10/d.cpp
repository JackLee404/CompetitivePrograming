#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

int a[6][6], d[6][6];

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

struct node {
	int x, y;
}path[6][6];

void bfs() {
	queue<PII> q1;
	memset(d, -1, sizeof d);
	q1.push(make_pair(1, 1));
	while (q1.size()) {
		PII t = q1.front(); q1.pop();	
		int x = t.first, y = t.second;
		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 1 && tx <= 5 && ty >= 1 && ty <= 5 && !a[tx][ty] && d[tx][ty] == -1) {
				d[tx][ty] = d[x][y] + 1;
				q1.push(make_pair(tx, ty));
				path[tx][ty].x = x, path[tx][ty].y = y;
			}
		}
	}
}

void print(int x, int y) {
	if (x == 1 && y == 1) {
		printf("(%d, %d)\n", x - 1, y - 1);
		return;
	}
	print(path[x][y].x, path[x][y].y);
	printf("(%d, %d)\n", x - 1, y - 1);
}

int main() {
	for (int i = 1; i <= 5; i ++) {
		for (int j = 1; j <= 5; j ++) {
			cin >> a[i][j];
		}
	}
	bfs();
	print(5, 5);
}