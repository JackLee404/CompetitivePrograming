#include <iostream>
#include <vector>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10, M = 1e2 + 10;

int f[2][M][2];

void solve() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> a(n + 1);

	memset(f, -0x3f, sizeof f);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	f[0][0][0] = f[1][0][0] = 0;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= k; j ++) {
			f[i & 1][j][1] = std::max(f[i - 1 & 1][j][1], f[i - 1 & 1][j - 1][0] - a[i]);
			f[i & 1][j][0] = std::max(f[i - 1 & 1][j][0], f[i - 1 & 1][j][1] + a[i]);
		}
	}

	int ans = 0;

	for(int i = 0; i <= k; i ++) ans = std::max(ans, f[n & 1][i][0]);


	std::cout << ans << "\n";
}

int main() {
	int _;

	// std::cin >> _;

	_ = 1;
	
	while(_ --) {
		solve();
	}
}