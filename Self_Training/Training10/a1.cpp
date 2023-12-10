#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	std::vector<int> ans(n + 10);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		if(!a[i]) continue;

		a[i] = std::min(a[i], i);

		ans[i - a[i] + 1] += 1;
		ans[i + 1] -= 1;
	}

	for(int i = 1; i <= n; i ++) {
		ans[i] += ans[i - 1];

		std::cout << (ans[i]?1:0) << " \n"[i == n];
	}
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}