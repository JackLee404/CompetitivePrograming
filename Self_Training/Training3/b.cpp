#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> arr(n);
	for(auto &x: arr) std::cin >> x;

	
	std::sort(arr.begin(), arr.end());

	int ans = (arr[0] > 0);

	for(int i = 0; i < n; i ++) {
		bool ok = (arr[i] <= i && (i == n - 1 || (arr[i + 1] > i + 1)));
		ans += ok;
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