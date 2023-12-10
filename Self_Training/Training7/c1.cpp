#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using i64 = long long;

const int N = 150;

int dp[N], v[N], w[N];

void solve() {
	int t, m;
	std::cin >> t >> m;

	rep(i, 1, m)
		std::cin >> v[i] >> w[i];

	rep(i, 1, t){
		per(j, m, i){
			dp[i] = std::max(dp[i], dp[i - v[i]] + w[i]);
		}
	}

	std::cout << dp[m];
}

int main() {
	int _;
	_ = 1;
	while(_ --) {
		solve();
	}
}