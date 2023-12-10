#include <bits/stdc++.h>

using i64 = long long;

int n;

std::vector<int> a;

bool check(int l, int r) {
	int st = l;
	for(int i = 1; i <= n; i ++) {
		if(a[i] >= l && a[i] <= r) {
			if(a[i] != st) return false;
			st ++;
		}
	}
	return true;
}

void solve() {
	std::cin >> n;

	a.resize(n + 1, 0);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	int l = 0, r = n / 2;

	while(l < r) {
		int mid = l + r >> 1;
		if(check(mid + 1, n - mid)) r = mid;
		else l = mid + 1;
	}

	std::cout << l << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}