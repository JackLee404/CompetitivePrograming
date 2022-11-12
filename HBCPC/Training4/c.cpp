#include <bits/stdc++.h>
#define pii pair<int, int>
#define f first
#define s second
using namespace std;

const int N = 200;
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
int n, m, cnt, d[N][N];
bool a[N][N], v[N][N];
queue<pii> q;
bool check(int x, int y){
    if (x >= n || x < 0 || y >= m || y < 0 || a[x][y] || v[x][y]) return false;
    return true;
}
int bfs(int x, int y){
	q.push({x, y});
	while (!q.empty()){
	    auto t = q.front();
		for (int i = 0; i < 4; i ++){
			int tx = t.f + dx[i], ty = t.s + dy[i];
			if (check(tx, ty)){
			    q.push({tx, ty}), v[tx][ty] = 1, d[tx][ty] = d[t.f][t.s] + 1;
			} 
		}
		q.pop();
	}
	return d[n - 1][m - 1];
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i ++)
		for (int j = 0; j < m; j ++)
			cin >> a[i][j];
	cout << bfs(0, 0);
}