#include <cstring>
#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <functional>
#include <utility>
// #include <unordered_set>
// #include <unordered_map>
#define INF 0x3f3f3f3f
#define IOS ios::sync_with_stdio(false);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
#define dbg1(a) cout << a << endl;
#define dbg2(a, b) cout << a << " " <<  b << endl;
#define dbg3(a, b, c) cout << a << " " << b << " " << c << endl;
#define pb(x) push_back(x)
#define eb(x) emplace_back(x)
#define all(x) x.begin(), x.end()
#define f first
#define s second
#define lc p<<1
#define rc p<<1|1
using namespace std;
// typedef long long LL;
// typedef priority_queue<int, vector<int>, greater<int>> S_HEAP;
// typedef priority_queue<int> B_HEAP;
// typedef pair<string, int> PSI;
// typedef pair<int, int> PII;
const int N = 1e5 + 10;
int L, R, C;
int dx[] = {0, 1, -1, 0, 0, 0}, dy[] = {1, 0, 0, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

char a[35][35][35];
int d[35][35][35];

struct tuples {
        int z, x, y;
};


void bfs(int sz, int sx, int sy) {
        memset(d, -1, sizeof d);
        queue<tuples> q1;
        tuples n1; n1.x = sx, n1.y = sy, n1.z = sz;
        q1.push(n1);
        d[sz][sx][sy] = 0;
        while (q1.size()) {
                tuples t = q1.front(); q1.pop();
                int z = t.z, x = t.x, y = t.y;
                if (a[z][x][y] == 'E') {
                        printf("Escaped in %d minute(s).\n", d[z][x][y]);
                        return;
                }
                //cout << z << x << y << endl;
                rep (i, 0, 5) {
                        int tx = x + dx[i], ty = y + dy[i], tz = z + dz[i];
                        if (tx >= 1 && tx <= R && ty >= 1 && ty <= C && tz <= L && tz >= 1 && d[tz][tx][ty] == -1 && a[tz][tx][ty] != '#') {
                                d[tz][tx][ty] = d[z][x][y] + 1;
                                tuples n1; n1.z = tz, n1.x = tx, n1.y = ty;
                                q1.push(n1);
                        }
                }
        }
        puts("Trapped!");
        return;
}

int main() {
        int sx, sy, sz;
        while (cin >> L >> R >> C, L || R || C) {
                rep (i, 1, L) {
                        rep (j, 1, R) {
                                rep (k, 1, C) {
                                        cin >> a[i][j][k];
                                        if (a[i][j][k] == 'S') {
                                                sx = j, sy= k, sz = i;
                                        }
                                }
                        }
                }
                bfs(sz, sx, sy);
        }
}