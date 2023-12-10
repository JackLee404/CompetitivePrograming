#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<std::map<i64, i64>> v(4);

	for (int i = 1; i <= n; i ++) {
		i64 x, y;

		std::cin >> x >> y;

		v[0][x] ++, v[1][y] ++, v[2][x + y] ++, v[3][x - y] ++;
	}

	i64 ans = 0;

	for (auto mp: v) {
		for (auto [k, v]: mp) {
			ans += v * (v - 1);
		}
	}

	std::cout << ans << "\n";
}



int main() {

	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}