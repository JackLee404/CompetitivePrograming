#include <bits/stdc++.h>

using i64 = long long;

/*
	1 3 2 3 1 5 2
	&运算 一定非递增

	只计算区间数量？

	什么时候需要分出区间-> 让总和最小
*/

void solve() {
	int n, t;

	std::cin >> n;

	std::vector<int> v1(n);

	for (auto &x: v1) std::cin >> x;

	t = v1[0];

	for (int i = 1; i < n; i ++) t &= v1[i];

	if (!t) {
		int t2 = v1[0], ans = 1;

		for (int i = 1; i < n; i ++) {
			if (!t2) {
				t2 = v1[i];
				ans ++;
			}
			t2 &= v1[i];
		}

		if (t2) ans --;

		std::cout << ans << "\n";
	} else {
		puts("1");	
	}
}

int main() {
	// std::cout << (5 & 7 & 12 & 6) << "-\n";

	int _;

	std::cin >> _;	

	while (_ --) { solve(); }
}