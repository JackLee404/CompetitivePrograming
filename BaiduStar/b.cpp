#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10, MOD = 1e9 + 7;

int fast_pow(int a, int k) {
	int res = 1;

	while (k) {
		if (k & 1) res = (i64) res * a % MOD;
		a = (i64)a * a % MOD;
		k >>= 1;
	}

	return res;
}

int C(int a, int b) {
	int res = 1;

	for (int i = 1, j = a; i <= b; i ++, j --) {
		res = (i64)res * j % MOD;
		res = (i64)res * fast_pow(i, MOD - 2) % MOD;
	}

	return res;
}

i64 lucas(i64 a, i64 b) {
	if (a < MOD && b < MOD) return C(a, b);
	return (i64) C(a % MOD, b % MOD) * lucas(a / MOD, b / MOD) % MOD;
}

int main() {
	i64 n;

	std::cin >> n;

	if (n < 10) {
		if (n == 9) puts("1");
		else puts("0");
	} else {
		i64 k = 1, t = 1;

		for (int i = 1; i <= n - 9; i ++) {
			t *= 4;
			if (t >= MOD) t %= MOD;
		}


		// res = res * fast_pow(t, MOD - 2) % MOD;


		for (int i = 1; i <= n - 9; i ++) {
			k *= 26;
			if (k >= MOD) k %= MOD;
		}

		// std::cout << t << " " << k << "\n";

		i64 res = (t * k) % MOD;

		std::cout << res;
	}
}