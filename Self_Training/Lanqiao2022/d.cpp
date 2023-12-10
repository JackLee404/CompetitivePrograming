#include <iostream>

using i64 = long long;

int main() {
	i64 n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cout << std::max((i64)2 * (i - 1), 2 * (n - i)) << "\n";
	}
}