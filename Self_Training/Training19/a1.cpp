#include <iostream>
#include <algorithm>
#include <cmath>

using i64 = long long;

const int N = 400;

int a[N];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	
	int n;
	i64 ans = 0;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::sort(a + 1, a + 1 + n, std::greater<int>());

	ans += a[1] * a[1];

	for (int i = 1; i <= n / 2; i ++) {
		ans += (i64) (a[i] - a[n - i + 1]) * (a[i] - a[n - i + 1]);
		ans += (i64) (a[i + 1] - a[n - i + 1]) * (a[i + 1] - a[n - i + 1]);
	}

	std::cout << ans;
}