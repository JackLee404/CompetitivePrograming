#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> v(n);	
	for(auto &x: v)
		std::cin >> x;

	i64 ans = v[0];

	v.erase(v.begin());

	std::sort(v.begin(), v.end());

	// for(int i = 0; i < n; i ++) {
	// 	std::cout << v[i] << " \n"[i == n - 1];
	// }

	for(int i = 0; i < v.size(); i ++) {
		// std::cout << v[i] << " \n"[i == v.size() - 1];
		if(v[i] > ans) {
			// std::cout << ans << " " << v[i] << std::endl;
			ans = (ans + v[i] + 1) / 2;	
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