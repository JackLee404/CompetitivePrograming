#include <bits/stdc++.h>

int n, m;

int main() {
	std::cin >> n >> m;

	int res = 0, ans = 0;

	for (int i = 1; i <= n; i ++) {
		int x; std::cin >> x;

		if (res + x > m) {
			ans ++, res = x;
			// if (res > m) res -= m, ans ++;
		} else {
			res += x;
		}
	}

	std::cout << ans;
}