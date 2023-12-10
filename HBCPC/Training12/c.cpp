#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 15, M = 3e5 + 10;


int n, m, t[N], d[N][N], dp[N][M];


void init() {
    for (int i = 0; i <= 11; i ++) {
        if (i == 0) t[i] = 1; 
        else t[i] = t[i - 1] * 3;
    }
}

int check(int j) {
    int cnt = 0, x;
    for (int i = 1; i <= n; i ++) {
        if ((j / t[i - 1]) % 3 == 0) cnt ++, x = i;
    }

    if (cnt != 1) return -1;
    return x;
}

int main() {
    init();
    // cout << t[3] << endl;
    // while (true) {
    //     int j;
    //     cin >> j;
    //     cout << (j / t[3]) % 3 << endl;
    // }
    while (cin >> n >> m) {
        memset(d, 0x3f, sizeof d);
        memset(dp, 0x3f, sizeof dp);

        for (int i = 1; i <= m; i ++) {
           int a, b, c;
           cin >> a >> b >> c;
           d[a][b] = d[b][a] = min(d[a][b], c);
        }


        for (int i = 1; i <= n; i ++) {
            dp[i][0] = d[i][1];
        }

        dp[1][0] = 0;

        int ans = INF;

        for (int j = 1; j < t[n]; j ++) {
            for (int i = 1; i <= n; i ++) {
               
                if ((j / t[i - 1]) % 3 >= 2) continue;

                for (int k = 1; k <= n; k ++) {
                    if ((j / t[k - 1]) % 3 == 0) continue;

                    int nj = j -((j / t[k - 1]) % 3);

                    // cout << i << " " << nj << endl;

                    dp[i][j] = min(dp[i][j], d[i][k] + dp[k][nj]);
                }
            }

            if (check(j) == 1) {
                cout << 1 << " " << j << " " << dp[1][j] << endl;
                ans = min(ans, dp[1][j]);
            }
        }


        cout << (ans >= INF/2?-1:ans) << endl;
    }
}