#include <bits/stdc++.h>

using i64 = long long;


std::vector<i64> v1;

int main() {
	i64 n;
	
	std::cin >> n;

	i64 ans = 0;

	for(i64 i = 1; i <= n / i; i ++) {
		if(n % i == 0) {
			v1.push_back(i);
			if(n / i != i) v1.push_back(n / i);
		}
	}

	// std::cout << v1.size();

	for(auto &x: v1) {
		for(auto &y: v1) {
			for(auto &z: v1) {
				if(x * y * z == n) {
					ans ++;
				}
			}
		}
	}

	std::cout << ans;
}