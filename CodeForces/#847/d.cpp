#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int cnt = 0, n = 0;

void solve() {
	int ans = 0;
	
	std::cin >> n;

	std::map<int, int> mp;

	for(int i = 1; i <= n; i ++) {
		int x;
		std::cin >> x;
		mp[x] ++;
	}

	for(auto& [x, y]: mp) {
		int k = mp[x] - mp[x - 1];
		if(!mp.count(x - 1)) ans += y;
		else ans += k < 0?0:k;
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