#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int ans = 0;

	i64 pos = 10;

	if(n <= 10) {
		ans = n;
	} else {
		ans = 10;
		int k = 10, ct = 1;

		while(pos * k <= n) {
			pos *= k;
			ans += 9; 
			ct ++;
		}

		if(n > pos) {
			int t = n / (i64)(pow(10, ct));
			// std::cout << (i64)(pow(10, ct)) << "\n";
			ans += t - 1;
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