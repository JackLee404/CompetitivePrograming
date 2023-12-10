#include <bits/stdc++.h>

using i64 = long long;

inline i64 func(i64 a) {
	if (a <= 1) return 1;
	else return a * func(a - 1);
}

int main() {
	int a, b;

	std::cin >> a >> b;

	std::cout << func(a + b);
}