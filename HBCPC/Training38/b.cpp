#include <bits/stdc++.h>

using i64 = long long;

const int N = 200;


void solve() {
	i64 n, k, g;

	std::cin >> n >> k >> g;	

	i64 stolen = std::min(k * g, (g - 1) / 2 * n);

	i64 rest = (k * g - stolen) % g;

	if (rest > 0) {
		stolen -= (g - 1) / 2;

		rest = (rest + (g - 1) / 2) % g;

		if (rest * 2 >= g) {
			stolen -= g - rest;
		} else {
			stolen += rest;
		}
	}

	std::cout << stolen << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}