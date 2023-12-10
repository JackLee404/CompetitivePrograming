#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> v(n);

	int ct1 = 0, ct2 = 0;

	int ans = 0;

	for (auto &x: v) {
		std::cin >> x;
		ct1 += (x == 1);
		ct2 += (x == -1);
	}

	if (ct2 > ct1) {
		while (ct2 > ct1) {
			ct1 ++;
			ct2 --;
			ans ++;
		}


		if (ct2 % 2) ct2 --, ct1 ++, ans ++;
	} else {
		if (ct2 % 2) ct2 --, ct1 ++, ans ++;			
	}

	std::cout << ans << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}