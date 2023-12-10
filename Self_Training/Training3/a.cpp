#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int w, d, h;
	int a, b, f, g;
	std::cin >> w >> d >> h;
	std::cin >> a >> b >> f >> g;
	// std::cout << (h + abs(a - f) + b + g) << "\n";
	int n1 = (h + abs(a - f) + std::min(b + g, d - b + d - g));
	int n2 = (h + abs(b - g) + std::min(a + f, w - a + w - f));
	std::cout << std::min(n1, n2) << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}