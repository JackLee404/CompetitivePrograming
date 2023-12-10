#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

i64 a, b;

int main() {
	std::cin >> a >> b;

	i64 sum = 0;

	for(int i = 1; i <= 5; i ++) {
		sum += 2 * a;
	}

	// std::cout <<

	if(sum >= b) {
		std::cout << "HZWZ";
	} else {
		std::cout << "DDJZ";
	}
}