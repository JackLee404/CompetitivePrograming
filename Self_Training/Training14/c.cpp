#include <iostream>
#include <vector>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1);

	std::vector<std::vector<int>> f(n + 2, std::vector<int>(2));

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for(int i = 1; i <= n + 1; i ++) {
		if(i != n + 1)
			f[i][1] = f[i - 1][0] + a[i];
		f[i][0] = std::max(f[i - 1][0], f[i - 1][1]);
	}

	std::cout << f[n + 1][0] << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}