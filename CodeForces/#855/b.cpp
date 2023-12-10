#include <bits/stdc++.h>

const int mod = 1e9 + 7;

using i64 = long long;

long long fac(i64 x) {
	if(x <= 1) return 1;
	return (fac(x - 1) % mod * x % mod) % mod;
}

void solve() {
	i64 n;
	std::cin >> n;
	i64 ans = (fac(n) % mod * ((n - 1) % mod * n % mod) % mod) % mod;

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}