#include <iostream>
#include <queue>
#include <string>
#include <cstring>
#define INF 0x3f3f3f3f
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using namespace std;
const int N = 20;

int dx[] = {0, -1, 1, 0, 0}, dy[] = {1, 0, 0, -1, 0};

int n, m, cnt, ans;

int a[N][N], b[N][N], t[N][N], act[N][N];

void flip(int x, int y) {
    rep (i, 0, 4) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx >= 1 && tx <= n && ty >= 1 && ty <= m) {
            t[tx][ty] = !t[tx][ty];
        }
    }
}

bool checkLine(int i) {
    rep (j, 1, m) {
        if (t[i][j])
            return false;
    }
    return true;
}

void print() {
    rep (i, 1, n) {
        cout << t[i][1];
        rep (j, 2, m) {
            cout << " " << t[i][j];
        }
        cout << "\n";
    }
}

void loop() {
    rep (i, 2, n) {
        rep (j, 1, m) {
            if (t[i - 1][j]) {
                flip(i, j);
                cnt ++;
                act[i][j] = 1;
                if (cnt >= ans) return;
            }
        }
        // cout << "1 line after" << endl;
        // print();
        // cout << endl;
    }

    // print();

    if (checkLine(n)) {
        if (cnt < ans) {
            memcpy(b, act, sizeof act);
            ans = cnt;
        }
    }
}



int main() {
    ans = INF;
    // cin >> n >> m;
    rep (i, 1, n)
        rep (j, 1, m)
            cin >> a[i][j];

    for (int i = 0; i < (1 << m); i ++) {
        cnt = 0;
        memset(act, 0, sizeof act);
        memcpy(t, a, sizeof t);
        // cout << i << endl;
        for (int j = 0; j < m; j ++) {
            if(i >> j & 1) {
                cnt ++;
                act[1][m - j] = 1;
                flip(1, m - j);
            }
        }
        // cout << "begin with" << endl;
        // print();
        // cout << endl;
        loop();
    }

    if (ans == INF) {
        cout << "IMPOSSIBLE";
    } else {
        rep (i, 1, n) {
            cout << b[i][1];
            rep (j, 2, m) {
                cout << " " << b[i][j];
            }
            cout << "\n";
        }
    }
}