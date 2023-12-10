#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e4 + 100;

int a[N];

void solve() {
	int n, c1, c2;

	std::cin >> n >> c1 >> c2;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	int ans = 0;

	std::sort(a + 1, a + 1 + n, std::greater<int>());

	int p1 = 0, p2 = 0;
	
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}