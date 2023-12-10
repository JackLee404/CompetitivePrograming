#include <bits/stdc++.h>

using i64 = long long;

i64 a, b, n;

i64 quick_pow(i64 a, i64 b, i64 m) {
	i64 res = 1;

	while (b) {
		if (b & 1) res = res * a % m;
		a = a * a % m;
		b >>= 1;
	}	

	return res;
}

int main() {
	std::cin >> a >> b >> n;

	a = a * quick_pow(10, n - 1, b) % b;

	for (int i = 1; i <= 3; i ++) {
		a *= 10;
		
		std::cout << a / b;	

		a %= b;
	}
}