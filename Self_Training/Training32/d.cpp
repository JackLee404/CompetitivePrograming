#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n);

	for (auto &x: a) std::cin >> x;

	for (int i = 0; i < n; i ++) {
		std::cout << (n + 1) - a[i] << " \n"[i == n - 1];
	}
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}