#include <iostream>
#include <queue>
#include <utility>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;

int n, m;


// 斜对角 x, y --> (x - 1, y - 1) , (x + 1, y + 1), (x - 1, y + 1), (x + 1, y - 1);

int dx[] = {0, -1, 1, 0, -1, 1, -1, 1}, dy[] = {1, 0, 0, -1, -1, 1, 1, -1};

char a[110][110];

bool st[110][110];

void dfs(int x, int y) {
	for (int i = 0; i < 8; i ++) {
		int tx = x + dx[i], ty = y + dy[i];
		if (tx <= n && tx >= 1 && ty <= m && ty >= 1 && a[tx][ty] == '@' && !st[tx][ty]) {
			st[tx][ty] = true;
			dfs(tx, ty);				
		}
	}
}

int main() {
	while (cin >> n >> m && n && m) {
		vector<PII> v1;
		int cnt = 0;
		memset(st, 0, sizeof st);
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				cin >> a[i][j];
				if (a[i][j] == '@') {
					v1.push_back(make_pair(i, j));
				}
			}
		}
		for (auto &it: v1) {
			int x = it.first, y = it.second;
			if (!st[x][y]) {
				dfs(x, y);
				cnt ++;
			}
		}
		cout << cnt << endl;
	}
}