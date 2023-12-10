#include <bits/stdc++.h>

using i64 = long long;

const int mod = 998244353, N = 1e6 + 5, Z = 32;

void add(int &x, int y) { if ((x += y) >= mod) x -= mod; }

i64 qmi(i64 a, i64 b = mod - 2) {
	i64 res = 1;
	a %= mod;
	while (b) { 
		if (b & 1) res = res * a % mod;
		a = a * a % mod; 
		b >>= 1;
	}
	return res;
}

i64 n, m;

int main() {
	std::cin >> n >> m;


	i64 ans = 1;

	for (int i = 1; i <= m;) {
		i64 lg = std::__lg(n + i);
		i64 v = (1 - qmi(1ll << lg) + mod) % mod;
		i64 j = std::min(m, (1 << (lg + 1)) - n - 1);
		(ans *= qmi(v, j - i + 1) % mod) %= mod;
		i = j + 1;
	}

	std::cout << ans;
}