#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using i64 = long long;

const int N = 2e4 + 5e3 + 10;

int dp[N];
int vis[N];

void solve() {
	memset(vis, 0, sizeof vis);
	int n, m = -1, ans = 0;

	std::cin >> n;
	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		m = std::max(m, a[i]);
	}

	std::sort(a.begin(), a.end());

	dp[0] = 1;

	for(int i = 1; i <= n; i ++) {
		if(!vis[a[i]]) ans ++;

		for(int j = a[i]; j <= m; j ++) {
			dp[j] = dp[j] + dp[j - a[i]];
			vis[dp[j]] = 1;
		}
	}	

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}