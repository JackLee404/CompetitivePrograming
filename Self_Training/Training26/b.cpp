#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

/*
    dp[i][j] 表示选到第i个数时，且结尾数字为j,此时结尾的最小删除值

    if (j == k) {
        dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1])
    } else {
        dp[i][j] = dp[i - 1][j - 1] + 1;
    }
*/

int n;

int dp[N][10];

int a[N];

int main() {
    std::cin >> n;

    for (int i = 1; i <= n; i ++) std::cin >> a[i];

    for (int i = 1; i <= n; i ++) {
        int k = a[i] % 10;
        for (int j = 0; j <= 9; j ++) {
            if (j == k) {
                dp[i][j] = std::min(dp[i - 1][k], );
            }
        }
    }
}