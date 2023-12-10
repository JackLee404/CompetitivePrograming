#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n, m, k;
	std::string x;
	
	std::cin >> n >> x >> m >> k;
	
	if (k == n) {
		std::cout << "mei you mai " << x << " de";
	} else if (k == m) {
		std::cout << "kan dao le mai " << x << " de";
	} else {
		std::cout << "wang le zhao mai " << x << " de";
	}
}