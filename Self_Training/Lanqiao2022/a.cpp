#include <iostream>
#include <algorithm>
#include <cmath>

using i64 = long long;

int main() {
	// int n;
	
	// std::cin >> n;

	i64 k = (2 + 2 * 9 + 2 * (9 * 9 * 9));

	std::string ans;

	for(int i = 0; (k >> i) > 0; i ++) {
		// std::cout << (k >> i & 1);

		ans.push_back((k >> i & 1) + '0');
	}

	std::reverse(ans.begin(), ans.end());

	std::cout << ans;
}