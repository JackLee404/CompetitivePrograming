#include <iostream>
#include <vector>
#include <cstring>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;

int n, m, k, sx, sy, ex, ey;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
bool st[10][10], flag;

int cal(int x, int y) {
    return abs(x - ex) + abs(y - ey);
}

vector<string> a(10);

void dfs(int x, int y, int remain_time) {
    int minstep = cal(x, y);
    //cout << x << " " << y << endl;
    if (a[x][y] == 'D' && remain_time == 0) {
       flag = true;
       return;
    }
    else if (remain_time < minstep || ((remain_time - minstep) & 1)) {
        return;
    }
     //// 3 3  1 1
    //cout << x << " " << y << " " << minstep << " " << remain_time << endl;

    rep (i, 0, 3) {
        int x1 = x + dx[i], y1 = y + dy[i];

        if (x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m && a[x1][y1] != 'X' && !st[x1][y1]) {
            //cout << x1 << " " << y1 << endl;
            st[x1][y1] = true;
            dfs(x1, y1, remain_time - 1);
            st[x1][y1] = false;
            if (flag) return;
        }
    }
}

int main() {
    while (cin >> n >> m >> k && n && m && k) {
        flag = false;
        memset(st, 0, sizeof(st));
        rep (i, 1, n)
            rep (j, 1, m){
                cin >> a[i][j];
                if (a[i][j] == 'S')
                    sx = i, sy = j;
                else if (a[i][j] == 'D')
                    ex = i, ey = j;
            }
        st[sx][sy] = true;
        dfs(sx, sy, k);
        puts(flag?"YES":"NO");
    }
}
