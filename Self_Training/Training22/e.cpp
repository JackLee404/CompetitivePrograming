#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cout << 'A' << " \n"[i == n];
	}

	for (int i = 1; i <= 4; i ++) {
		if (i == 1) {
			std::cout << "A:" << n;
		} else {
			std::cout << " " << char('A' + i - 1) << ":0";
		}
	}
}