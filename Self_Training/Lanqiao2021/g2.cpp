#include <iostream>
#include <algorithm>

using i64 = long long;

const int M = 1e5 + 1000, N = 1e5;

i64 dp[300][M];

int v[300], ans;

int main() {
    int n;

    std::cin >> n;

    for(int i = 1; i <= n; i ++) {
        std::cin >> v[i];
    }

    for(int i = 0; i <= n; i ++) {
        dp[i][0] = 1;
    }

    for(int i = 1; i <= n; i ++) {
        for(int j = 1; j <= N; j ++) {
            dp[i][j] = dp[i - 1][j] + dp[i - 1][std::abs(j - v[i])] + dp[i - 1][std::min(j + v[i], N)];
        }
    }

    for(int i = 1; i <= M; i ++) {
        ans += (bool) dp[n][i];  
    }

    std::cout << ans;
}