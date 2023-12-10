#include <iostream>

using i64 = long long;

int main() {
	int n, ans = 0, t = 1;

	std::cin >> n;

	while(n) {
		ans = ans + (n % 10) * t;

		std::cout << n % 10 << " " << t << "\n";
		n /= 10;
		t *= 9;
	}

	std::cout << ans;
}