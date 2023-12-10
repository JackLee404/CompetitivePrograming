#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PLL;


PLL calc(i64 n, i64 m) {
	if(n == 0) return {0, 0};
	i64 len = 1ll << n - 1, cnt = 1ll << 2 * (n - 1);
	auto pos = calc(n - 1, m % cnt);
	auto x = pos.first, y = pos.second;
	auto z = m / cnt;
	if(z == 0) return {y, x};
	if(z == 1) return {x, y + len};
	if(z == 2) return {x + len, y + len};
	return {2 * len - 1 - y, len - 1 - x};
}

void solve() {
	i64 n, a, b;

	std::cin >> n >> a >> b;

	auto ac = calc(n, a - 1);
	auto bc = calc(n, b - 1);
	double x = ac.first - bc.first, y = ac.second - bc.second;

	printf("%.0lf\n", sqrt(x * x + y * y) * 10);
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}