#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#define rep(i, j, k) for (int i = j; i <= k; i ++)

using namespace std;
typedef pair<int, int> PII;

int n, m, d[110][110];
int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};

char mp[110][110];

bool judge = false, vis[110][110];

struct node {
        int x, y, dis;
        bool operator < (struct node b) const& {
                return this->dis > b.dis;
        }
};

struct road {
        int x, y, sec;
};

vector<road> res;

road path[110][110];

void print(int x, int y) {

        if (x == 1 && y == 1) {
                res.push_back({x, y, 0});
                return;
        }
        else {
                print(path[x][y].x, path[x][y].y);
        }
        res.push_back({x, y, 0});
        //cout << x - 1 << " " << y - 1 <<  " " << path[x][y].sec << endl;
}

bool check(int x, int y) {
        return x >= 1 && x <= n && y >= 1 && y <= m && d[x][y] == -1 && mp[x][y] != 'X' && !vis[x][y];
}

void bfs() {
        memset(d, -1, sizeof d);
        memset(vis, 0, sizeof vis);
        priority_queue<node> heap;
        res.clear();
        heap.push({1, 1, 0});
        d[1][1] = 0;
        while (heap.size()) {
                auto t = heap.top();
                heap.pop();
                //cout << t.x << " " << t.y << endl;
                if (t.x == n && t.y == m) {
                        judge = true;
                        printf("It takes %d seconds to reach the target position, let me show you the way.\n", t.dis);
                        print(n, m);
                        for (int i = 1; i < res.size(); i ++) {
                                int x = res[i].x, y = res[i].y, lx = res[i - 1].x, ly = res[i - 1].y;
                                int sec = d[x][y] + 1;
                                printf("%ds:(%d,%d)->(%d,%d)\n",sec,lx - 1,ly - 1,x - 1,y - 1);
                                if (mp[x][y] != '.') {
                                        for (int i = 1; i <= mp[x][y] - '0'; i ++) {
                                                printf("%ds:FIGHT AT (%d,%d)\n",sec + i, x - 1, y - 1);
                                        }
                                }
                        }
                        return;
                }
                rep (i, 0, 3) {
                        int tx = t.x + dx[i], ty = t.y + dy[i];
                        if (check(tx, ty)) {
                                node a = {tx, ty, 0};
                                if (mp[tx][ty] != '.')
                                        a.dis = t.dis + mp[tx][ty] - '0' + 1;
                                else
                                        a.dis = t.dis + 1;
                                d[tx][ty] = t.dis;
                                heap.push(a);
                                vis[tx][ty] = true;
                                path[tx][ty].x = t.x, path[tx][ty].y = t.y, path[tx][ty].sec = t.dis;
                        }
                }
        }
}


int main() {
        while (cin >> n >> m) {
                judge = false;
                rep (i, 1, n)
                        rep (j, 1, m)
                                cin >> mp[i][j];
                bfs();
                if (!judge)
                        cout << "God please help our poor hero." << endl;
                cout << "FINISH" << endl;
        }
}