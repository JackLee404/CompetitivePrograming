#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n = 10;
	
	while (n --) {
		std::cout << std::rand() % (9 - 1 + 1) + 1 << "\n";
	}
}