#include <algorithm>
#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 100;

int v[20], cnt = 0;

int dp[N][N];

bool st[N];

 // dp[i] 前i个数中 不超过c1 + c2的最大体积

void solve() {
	memset(st, false, sizeof st);

	int n, c1, c2, ans = 1;

	std::cin >> n >> c1 >> c2;

	for (int i = 1; i <= n; i ++) std::cin >> v[i];
	while (true) {
		for (int i = 1; i <= n; i ++) {
			if (st[i]) {
				dp[i] = dp[i - 1];
			} else {
				
			}
		}
	}
}

int main() {
	int t;

	std::cin >> t;

	while (t --) {
		solve();
	}		
}