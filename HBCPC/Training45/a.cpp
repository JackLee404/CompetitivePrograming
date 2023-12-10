#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x;

	std::cin >> x;

	std::string s1 = std::to_string(x);

	for (int i = 0; log2(x) + 1 + i <= 18; i ++) {
		i64 y2 = x * pow(10, i);
		i64 t = ceil(std::sqrt(y2));

		std::cout << t << "\n";
		
		if (t * t == y2 && !std::to_string(y2).find(s1)) {
			return std::cout << t << "\n", void(0);
		}
	}

	puts("-1");
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }		
}