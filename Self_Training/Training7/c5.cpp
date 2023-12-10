#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using i64 = long long;

/*
	完全背包
	dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
*/

const int N = 1e3 + 5;

int dp[N], v[N];

int main() {	
	int n, m;
	std::cin >> m;

	n = 4;

	v[1] = 10, v[2] = 20, v[3] = 50, v[4] = 100;

	rep(i, 0, n)
		dp[i] = 1;

	rep(i, 1, n) {
		rep(j, v[i], m) {
			dp[j] = dp[j] + dp[j - v[i]];
		}
	}

	std::cout << dp[m];
}