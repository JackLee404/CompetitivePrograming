#include <iostream>

using i64 = long long;

int g(int x) {
	return x ^ (x >> 1);
}

void out(int x, int n) {
	for (int i = 0; i < n; i ++) {
		std::cout << (x >> i & 1);
	}
	puts("");
}

int n;

int main() {
	std::cin >> n;

	for (int i = 0; i < (1 << n); i ++) {
		std::cout << i << " ", out(g(i), n);
	}
}