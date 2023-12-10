#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;


std::vector<std::string> v1;

int main() {
	int n;

	std::cin >> n;

	v1.resize(n);

	for (auto &x: v1) std::cin >> x;

	std::sort(v1.begin(), v1.end());

	for (int i = 0; i < n; i ++) {
		std::cout << v1[i] << " \n"[i == n - 1];
	}
}