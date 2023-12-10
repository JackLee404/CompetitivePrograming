#include <iostream>
#include <cstdio>
#include <cmath>

using i64 = long long;

const int N = 1e4 + 10;

int f[N];

int main() {
	// int n;

	// std::cin >> n;


	int cnt = 1, k = 1;

	for (int i = 1; i <= 10000; i ++) {
		f[i] = f[i - 1] + cnt;

		k --;

		if (!k) cnt ++, k = cnt;
	}

	int x;

	while (std::cin >> x, x) {
		std::cout << x << " " << f[x] << "\n";
	}
}