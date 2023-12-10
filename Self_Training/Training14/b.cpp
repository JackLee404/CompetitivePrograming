#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1), dp(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	dp[1] = a[1];

	for(int i = 2; i <= n; i ++) {
		dp[i] = std::max(dp[i - 2] + a[i], dp[i - 1]);
	}

	std::cout << dp[n] << "\n"
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}