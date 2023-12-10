#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::string t;
	// std::cin >> t;

	getline(std::cin, t);

	for (int i = 0; i < t.size(); i ++) {
		std::cout << t[i];
		if (i != (int) t.size() - 1) {
			std::cout << "-";
		}
	}
}