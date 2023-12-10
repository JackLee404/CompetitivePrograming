#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

int n, k, m, a[N];

std::unordered_map<int, int> h1, h2;

/*
	三元组(x/k^2, x/k, x)

	枚举x， 并维护h1[x] 记录 x 和 x / k对数， 且保证下标递减
*/

int main() {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	i64 res = 0;

	for (int i = 1; i <= n; i ++) {
		if (a[i] % k == 0) {
			res += h2[a[i] / k];
			h2[a[i]] += h1[a[i] / k];
		}
		h1[a[i]] ++;
	}

	std::cout << res;
}