#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

const int N = 2e4 + 10;

int stk[N], len;

// LDS

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}



	stk[0] = -2e9;
	len = 0;

	int ans;

	for(int i = 1; i <= n; i ++) {
		int l = 0, r = len;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(stk[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		stk[l + 1] = a[i];
		len = std::max(len, l + 1);
	}

	ans = len;
	len = 0;

	std::reverse(a.begin() + 1, a.end());

	for(int i = 1; i <= n; i ++) {
		int l = 0, r = len;
		while(l < r) {
			int mid = l + r + 1 >> 1;
			if(stk[mid] < a[i]) l = mid;
			else r = mid - 1;
		}
		stk[l + 1] = a[i];
		len = std::max(len, l + 1);
	}

	std::cout << std::max(ans, len) << "\n";
}

int main() {
	int _;
	std::cin >> _;

	while(_ --) {
		solve();
	}
}