#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10, INF = 1e9;

template <typename T>
inline T nxt() {
	T x; std::cin >> x;
	return x;
}

/*
	dp[i][4]

    1: no
    2: one & nomove
    3: one & move
    4: two & nomove
*/

i64 dp[N][5];

void solve() {
	int n = nxt<int>();

	std::vector<int> a(n + 1), b(n + 1);

	for (int i = 1; i <= n; i ++) {
		a[i] = nxt<int>();
	}

	for (int i = 1; i <= n; i ++) {
		b[i] = nxt<int>();
	}

    memset(dp, -0x3f, sizeof dp);

    if (b[1]) {
        dp[1][1] = a[1];
    } else {
        dp[1][0] = 0;
    }

    for (int i = 2; i <= n; i ++) {
        if (b[i]) {
            dp[i][0] = dp[i - 1][0] + a[i - 1];
            dp[i][1] = std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]}) + a[i]; 
            dp[i][3] = std::max(dp[i - 1][1] - a[i - 1] + a[i], dp[i - 1][3] + a[i]);
        } else {
            dp[i][0] = std::max({dp[i - 1][0], dp[i - 1][1], dp[i - 1][2], dp[i - 1][3]});
            dp[i][2] = std::max({dp[i - 1][1] - a[i - 1] + a[i], dp[i - 1][3] + a[i]});
        }
    }

    std::cout << std::max({dp[n][1], dp[n][2], dp[n][0]});
}

int main() {
    int _ = 1;
    while (_ --) { solve(); }
}