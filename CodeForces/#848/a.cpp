#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	int mx = -0x3f3f3f3f;
	int ans = -1;

	for(int i = 2; i <= n; i ++) {
		int k = -a[i] + -a[i - 1];
		if(k > mx) {
			ans = i;
			mx = k;
		}
	}

	a[ans] *= -1, a[ans - 1] *= -1;

	std::cout << std::accumulate(a.begin(), a.end(), 0ll) << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}