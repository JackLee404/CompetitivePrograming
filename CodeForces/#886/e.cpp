#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 n, c;

	std::cin >> n >> c;	


	std::vector<i64> a(n + 1);

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	i64 l = 0, r = sqrt(c) + 1;

	while (l < r) {
		i64 mid = l + r + 1 >> 1;

		i64 sum = 0;

		for (i64 i = 1; i <= n; i ++) {
			sum += (a[i] + 2 * mid) * (a[i] + 2 * mid);

			if (sum >= 1e18) {
				break;
			}
		}

		if (sum <= c) l = mid;
		else r = mid - 1;
	}

	std::cout << l << "\n";
}



int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}