#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;
	std::cin >> n;

	std::vector<int> v(n);

	for(auto &x: v) std::cin >> x;

	std::sort(v.begin(), v.end());

	for(int i = 0, j = n - 1; i <= j; i ++, j --) {
		if(i != j)
			std::cout << v[j] << "\n" << v[i] << std::endl;
		else if(i == j) {
			if(n % 2 != 0) {
				std::cout << v[j] << std::endl;
			}
		}
	}
}