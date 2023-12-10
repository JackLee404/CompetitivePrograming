#include <bits/stdc++.h>

using i64 = long long;

const int N = 2030;

int a[N], cnt1;

bool st[N];

i64 dp[N][N];

/*
	dp[i][j] 表示考虑前i个物品， 和恰好为j的方案数
*/

bool check(int x) {
	for (int i = 2; i <= x / i; i ++) {
		if (x % i == 0) {
			return false;
		}	
	}
	return true;
}

int main() {
	for (int i = 2; i <= 2019; i ++) {
		if (check(i)) a[++ cnt1] = i;
	}

	for (int i = 0; i <= cnt1; i ++)
		dp[i][0] = 1;

	for (int i = 1; i <= cnt1; i ++) {
		for (int j = 1; j <= 2019; j ++) {	
			dp[i][j] = dp[i - 1][j];

			if (j >= a[i]) dp[i][j] += dp[i - 1][j - a[i]];
		}
	}

	std::cout << dp[cnt1][2019] << "\n";
}