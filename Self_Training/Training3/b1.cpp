#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, m;
	std::cin>>n>>m;

	std::vector<int> st(n + 1, n);

	i64 ans = 0;

	for(int i = 1; i <= m; i ++) {
		int a, b;
		std::cin >> a >> b;
		if(a > b) std::swap(a, b);

		st[a] = std::min(st[a], b - 1);
		// std::cout << st[a] << std::endl;
	}

	for(int i = n - 1; i >= 1; i --) {
		st[i] = std::min(st[i], st[i + 1]);
		// std::cout << st[i] << " \n"[i == 1];
	}

	for(int i = 1; i <= n; i ++) {
		ans += st[i] - i + 1;
	}

	std::cout << ans << "\n";
}

int main() {
	int _; std::cin >> _;
	while(_ --) {
		solve();
	}
}