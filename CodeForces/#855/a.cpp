#include <bits/stdc++.h>

/*
	奇数 * 奇数 = 奇数
	奇数 * 偶数 = 偶数
	偶数 * 偶数 = 偶数
*/

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);

	for(auto &x: v) std::cin >> x;

	int ans = 0;

	for(int i = 0; i < n; i ++) {
		if(i) {
			if(v[i] % 2 == v[i - 1] % 2) {
				ans ++;
			}
		}
	}

	std::cout << ans << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}