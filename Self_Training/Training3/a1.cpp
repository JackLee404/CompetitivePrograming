#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n; std::cin>>n;
	std::vector<int> a(n);
	for(auto &x: a) std::cin >> x;
	int mx = *std::max_element(a.begin(), a.end());
	int mi = *std::min_element(a.begin(), a.end());
	int cnt1 = 0, cnt2 = 0;
	if(mx == mi) {
		for(auto &x: a) if(x == mx) cnt1 ++;
		std::cout << (i64)cnt1 * (cnt1 - 1) << "\n";
		return;
	}
	for(auto &x: a) {
		if(x == mx) cnt1 ++;
		if(x == mi) cnt2 ++;
	}
	std::cout << (i64)cnt1 * cnt2 * 2 << "\n";
}

int main() {
	int _; std::cin >> _;
	while(_ --) {
		solve();
	}
}