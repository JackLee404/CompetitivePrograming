#include <bits/stdc++.h>

using i64 = long long;

const i64 E = 1e9;

int main() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::sort(a.begin(), a.end());


	i64 k = 0;

	if((E - a[0]) * 2 > E) {
		std::cout << E << " " << E;
	} else {
		std::cout << 0 << " " << E;
	}
}