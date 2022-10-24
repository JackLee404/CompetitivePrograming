#include <iostream>
#include <cstdio>
#include <cstring>
#include <utility>
#include <queue>
#define rep(i, j, k) for(int i = j; i <= k; ++i)
#define f first
#define s second
#define PII pair<int, int>

const int N = 510;

using namespace std;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0}, d[N][N], a[N][N], b[N][N], n, m;
queue<PII> q1;

bool check(int x, int y) {
        return x <= n && x >= 1 && y >= 1 && y <= m;
}

void bfs() {
        memset(d, -1, sizeof d);
        rep (i, 1, n) {
                rep (j, 1, m) {
                        if (a[i][j]) d[i][j] = 0;
                }
        }
        while (q1.size()) {
                PII n = q1.front();
                q1.pop();
                int x = n.f, y = n.s;
                rep (i, 0, 3) {
                        int nx = x + dx[i], ny = y + dy[i];
                        if (check(nx, ny) && d[nx][ny] == -1) {
                                d[nx][ny] = d[x][y] + 1;
                                q1.push({nx, ny});
                        }
                }
        }
}


int main() {
        cin >> n >> m;
        rep(i, 1, n)
                rep(j, 1, m) {
                        cin >> a[i][j];
                        if (a[i][j]) q1.push({i, j});
                }

        bfs();

        rep(i, 1, n){
                rep(j, 1, m) {
                        if (j == 1)
                                cout << d[i][j];
                        else
                                cout << " " << d[i][j];
                }
                if (i != n)
                        cout << "\n";
        }
}
