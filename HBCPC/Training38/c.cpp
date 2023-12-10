#include <bits/stdc++.h>

using i64 = long long;

void answer(i64 a, i64 b) {
	std::cout << a << " + " << b << " = " << a + b << "\n";
}

void solve() {
	i64 a, b, c, k;

	std::cin >> a >> b >> c >> k;

	bool ok = false;

	for (i64 k1 = std::pow(10, a - 1); k1 < std::pow(10, a); k1 ++) {
		i64 left = std::max(std::pow(10, c - 1) - k1, std::pow(10, b - 1));
		i64 right = std::min(std::pow(10, c) - k1 - 1, std::pow(10, b) - 1);

		if (left > right) continue;

		int have = right - left + 1;

		if (k <= have) {
			answer(k1, left + k - 1);
			ok = true;
			break;	
		}

		k -= have;	
	}	

	if (!ok) puts("-1");
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}		
}