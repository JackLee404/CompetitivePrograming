#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int a[N];

int main() {
	int n, m;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::cin >> m;

	for(int i = 1; i <= m; i ++) {
		int x, y;

		std::cin >> x >> y;

		std::swap(a[x], a[y]);
	}

	for(int i = 1; i <= n; i ++) {
		std::cout << a[i] << " \n"[i == n];
	}
}