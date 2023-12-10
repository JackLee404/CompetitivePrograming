#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;
	std::cin >> n >> k;
	std::vector<int> arr(n);
	for(auto &x: arr) {
		std::cin >> x;
	}

	int p = 1;
	for(int i = 0; i < n; i ++) {
		if(arr[i] == p) p ++;
	}


	std::cout << ((p != n + 1)?((n - p + k) / k):0) << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}