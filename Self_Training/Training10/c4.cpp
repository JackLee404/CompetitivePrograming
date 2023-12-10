#include <bits/stdc++.h>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	std::vector<int> a(n);

	int ans = 0;

	for(auto &x: a) std::cin >> x;

	int j;

	for(int i = 0; i < n; i ++) {
		j = i;
		while(a[j] == a[j - 1] && j < n) j ++;

		
		if(j - i + 1 != 1) {
			ans += j - i + 1;
			i = j - 1;
		}		
	}

	// std::cout << ans;

	std::cout << n - ans;
}