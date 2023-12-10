#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<i64> prefix(n + 1, 0), a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		prefix[i] = a[i] + prefix[i - 1];
	}
	i64 ans = -1, last = 0;
	for(int mid = 1; mid <= n - 1; mid ++) {
		ans = std::max(ans, std::__gcd(prefix[mid], prefix[n] - prefix[mid]));
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