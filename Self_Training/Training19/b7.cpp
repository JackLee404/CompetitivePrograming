#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

void solve() {
	int n, m;

	std::cin >> n >> m;

	std::vector<std::vector<int>> v(m + 1, std::vector<int>(n + 1));

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> v[j][i];
		}
	}

	i64 ans = 0;

	for (int j = 1; j <= m; j ++) {
		i64 sum = 0;
		std::sort(v[j].begin() + 1, v[j].end());
		for (int i = 1; i <= n; i ++) {
			ans += (1LL * v[j][i] * (i - 1)) - sum;
			sum += v[j][i];
		}
	}

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;

	while (_ --) {
		solve();
	}
}