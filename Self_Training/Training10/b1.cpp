#include <bits/stdc++.h>


using i64 = long long;

const int N = 2e3 + 100, M = 1e3 + 10, mod = 1e8;

int dp[2][M], a[N];

int add(i64 a, i64 b) {
	return (a + b) % mod;
}

/*
	dp[i][j] 表示考虑前i头牛， 当能力x%f=j时的总方案数(j<f)

	则dp[i][j] = dp[i][j] + dp[i - 1][j] + dp[i][(j - a[i])]
*/

void solve() {
	int n, f;

	std::cin >> n >> f;
    
    int x;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i], a[i] %= f;
	}

	dp[0][0] = 1;

	for(int i = 1; i <= n; i ++) {
		
		for(int j = 0; j < f; j ++) {
			dp[i & 1][j] = add(dp[(i - 1) & 1][j], dp[(i - 1) & 1][(j - a[i] + f) % f]);
		}
	}
	
	std::cout << (dp[n & 1][0] - 1) % mod;
}


int main() {	
	int _;
	_ = 1;

	while(_ --) {
		solve();
	}
}