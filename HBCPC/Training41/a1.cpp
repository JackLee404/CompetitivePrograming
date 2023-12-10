#include <bits/stdc++.h>
#include <algorithm>

using i64 = long long;

/*
	a or b?

*/

void solve() {
	int a, b;

	std::cin >> a >> b;

	if (a > 1) {
		puts("1");
	} else {
		std::cout << a + b << "\n";
	}
}

int main() {
	int _;

	std::cin >> _;	

	while (_ --) { solve(); }
}