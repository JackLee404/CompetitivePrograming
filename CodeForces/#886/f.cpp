#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::map<int, int> mp;

	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		mp[a[i]] ++;
	}

	int ans = 0;

	for (auto &[k, v]: mp) {
		for (int i = k; i <= n; i += k) {
 			b[i] += v;

 			ans = std::max(ans, b[i]);
		}
	}

	std::cout << ans << "\n";
}



int main() {

	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}