#include <iostream>
#include <cstdio>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	int k = 0;

	for (int i = n; ; i ++) {
		int k = 0, t = i;

		while (t > 0) {
			k += (t % 10);

			t /= 10;
		}

		if (k % 4 == 0) {
			std::cout << i;
			break;
		}
	}
}