#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n, r0;

	std::cin >> n >> r0;

	i64 sum = 0;

	int cnt = 0;

	while (sum <= n) {
		sum += pow(r0, cnt ++);
	}

	if (!cnt) {
		std::cout << 0;
		return 0;
	}

	std::cout << cnt;
}