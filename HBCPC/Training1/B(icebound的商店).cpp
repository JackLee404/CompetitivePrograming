#include <iostream>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
const int N = 3010, M = 1e9 + 9;
int w[20], f[21][N];
using namespace std;

int main() {
    w[1] = 1, w[2] = 2;
    rep (i, 3, 15) {
        w[i] = w[i - 1] + w[i - 2];
    }


    rep (j, 0, 15) {
        f[j][0] = 1;
    }


    rep (i, 1, 15) {
        rep (j, 1, 3000) {
            if (j < w[i])
                f[i][j] = f[i - 1][j];
            else
                f[i][j] = (f[i][j - w[i]] + f[i - 1][j]) % M;
        }
    }

    int t;
    cin >> t;
    while (t --) {
        int x;
        cin >> x;
        cout << f[15][x] << endl;
    }
}


/*
 * f[i][j] = f[i - 1][j] + f[i][j - v[i]] + w[i]
 */
