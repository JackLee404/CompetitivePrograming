#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int f[N][2], w[N];

void solve() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) std::cin >> w[i];

	for(int i = 1; i <= n; i ++) {
		f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
		f[i][1] = f[i - 1][0] + w[i];
	}

	std::cout << std::max(f[n][0], f[n][1]) << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}