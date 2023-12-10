#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> PII;

const int N = 1e3 + 10;

int n, m, ans = -1;

int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

char a[N][N];
bool vis[N][N];
int dep[N][N];
queue<PII> q1;

int bfs() {
	while (q1.size()) {
		auto t = q1.front(); q1.pop();
		int x = t.first, y = t.second;
        ans = max(dep[x][y], ans);
		for (int i = 0; i <= 3; i ++) {
			int tx = x + dx[i], ty = y + dy[i];
			if (tx >= 1 && tx <= n && ty >= 1 && ty <= m && !vis[tx][ty]) {
                vis[tx][ty] = true;
                dep[tx][ty] = dep[x][y] + 1;
				q1.push({tx, ty});
			}
		}
	}
	return ans;
}

int main() {
	bool ck = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++){
		scanf("%s", a[i] + 1);
    }
    for (int i = 1; i <= n; i ++) 
   		for (int j = 1; j <= m; j ++) {
   			if (a[i][j] & !ck) {
   				ck = true; q1.push({i, j});
   			}
   		}
	cout << bfs();
}