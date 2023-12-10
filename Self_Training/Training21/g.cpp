#include <iostream>

using i64 = long long;

int main() {
	i64 n;

	std::cin >> n;

	std::cout << n;

	n /= 2;

	while (n) {
		std::cout << " " << n;
		n /= 2;
	}
}