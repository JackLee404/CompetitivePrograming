#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#include <map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
const int N = 15, M = 3e5;


int n, m, t[N], d[N][N], dp[N][M], bit[M][N];

void init() {
    for (int i = 0; i <= 11; i ++) {
        if (i == 0) t[i] = 1; 
        else t[i] = t[i - 1] * 3;
    }

    for (int i = 0; i <= t[10]; i ++) {
        int t = i;
        for (int j = 0; j <= 10; j ++) {
            bit[i][j] = t % 3;
            t /= 3; 
        }
    }

}

int check(int j) {
    for (int i = 0; i < n; i ++) {
        if (bit[j][i] == 0) return 0;
    }
    return 1;
}

int main() {
    init();
    while (cin >> n >> m) {
        memset(d, 0x3f, sizeof d);
        memset(dp, 0x3f, sizeof dp);

        for (int i = 1; i <= m; i ++) {
           int a, b, c;
           cin >> a >> b >> c;
           a--, b--;
           d[a][b] = d[b][a] = min(d[a][b], c);
        }

        // dp[i][j] 表示在j状态下以i为终点 所需要的最小权值

        for (int i = 0; i < n; i ++) {
            dp[i][t[i]] = 0;
        }

        int ans = INF;

        for (int j = 0; j < t[n]; j ++) {
            for (int i = 0; i < n; i ++) {
                for (int k = 0; k < n; k ++) {
                    if (bit[j][k] >= 2) continue;
                    if (d[i][k] != INF)
                        dp[k][j + t[k]] = min(dp[k][j + t[k]], d[i][k] + dp[i][j]);
                }
                if (check(j)) {
                    ans = min(ans, dp[i][j]);
                }
            }
        }


        cout << (ans >= INF/2?-1:ans) << endl;
    }
}