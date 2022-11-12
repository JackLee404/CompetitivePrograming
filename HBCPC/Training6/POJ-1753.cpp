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

int a[N][N], b[N][N], t[N][N];

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
                if (cnt >= ans) return;
            }
        }
        // cout << "1 line after" << endl;
        // print();
        // cout << endl;
    }

    // print();

    if (checkLine(n)) {
        ans = min(ans, cnt);
    }
}



int main() {
    ans = INF;
    n = 4, m = 4;
    rep (i, 1, n)
        rep (j, 1, m) {
                char c;
                cin >> c;
                if (c == 'w') {
                        a[i][j] = 0;
                        b[i][j] = 1;
                } else a[i][j] = 1, b[i][j] = 0;
        }

    for (int i = 0; i < (1 << m); i ++) {
        cnt = 0;
        memcpy(t, a, sizeof t);
        // cout << i << endl;
        for (int j = 0; j < m; j ++) {
            if(i >> j & 1) {
                cnt ++;
                flip(1, m - j);
            }
        }
        // cout << "begin with" << endl;
        // print();
        // cout << endl;
        loop();
    }


    for (int i = 0; i < (1 << m); i ++) {
        cnt = 0;
        memcpy(t, b, sizeof t);
        // cout << i << endl;
        for (int j = 0; j < m; j ++) {
            if(i >> j & 1) {
                cnt ++;
                flip(1, m - j);
            }
        }
        // cout << "begin with" << endl;
        // print();
        // cout << endl;
        loop();
    }

    if (ans == INF) {
        cout << "Impossible";
    } else {
        cout << ans;
    }
}