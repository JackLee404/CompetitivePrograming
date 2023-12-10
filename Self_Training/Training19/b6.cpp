#include <iostream>

using i64 = long long;

int calc(int x) {
	int mx = x % 10, mi = x % 10;

	while(x) {
		mx = std::max(x % 10, mx);
		mi = std::min(x % 10, mi);
		x /= 10;
	}

	return mx - mi;
}

void solve() {
	int l, r;

	std::cin >> l >> r;

	std::pair<int, int> ans;

	ans.first = 0;

	for (int i = l, j = 1; j <= 100 && i <= r; i ++, j +) {
		ans = std::max(ans, {calc(i), i});
	}

	std::cout << ans.second << "\n";
}

int main() {
	int _;
	std::cin >> _;

	while(_ --) {
		solve();
	}
}