#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> a(n + 1);

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	std::sort(a.begin() + 1, a.end());

	if (n == 1) {
		return puts("0"), void(0);
	}

	int l = 1, ans = 0;

	for (int i = 2; i <= n; i ++) {
		if (a[i] - a[i - 1] > k) {
			// std::cout << l << " " << i << "--\n";
			ans = std::max(ans, i - l);
			l = i;
		}
	}	

	

	ans = std::max(ans, n + 1 - l);

	std::cout << n - ans << "\n";
}



int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}