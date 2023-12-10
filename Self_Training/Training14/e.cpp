#include <iostream>
#include <vector>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10, M = 1e2 + 10;

// f[i][state] 表示第i天的状态的最优解
int f[N][3];

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	memset(f, -0x3f, sizeof f);

	f[0][2] = 0;

	for(int i = 1; i <= n; i ++) {
		f[i][0] = std::max(f[i - 1][0], f[i - 1][2] - a[i]);
		f[i][1] = f[i - 1][0] + a[i];
		f[i][2] = std::max(f[i - 1][1], f[i - 1][2]);
	}

	std::cout << std::max(f[n][1], f[n][2]);
}

int main() {
	int _;

	// std::cin >> _;

	_ = 1;
	
	while(_ --) {
		solve();
	}
}