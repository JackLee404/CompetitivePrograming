#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int a, b;

	std::cin >> a >> b;

	if (a > 0 && b > 0) {
		std::cout << std::max(a, b) << " " << a + b << "\n";
		puts("^_^");
	} else if (a < 0 && b < 0) {
		// std::cout << 0 << " " << 0;
		puts("-_-");
	} else {
		std::cout << std::max(a, b) << " " << 0 << "\n";
		puts("T_T");
	}
}