#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int a[N];

int main() {
	int n, ok = 0;
	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		ok ^= a[i];
	}

	std::cout << (ok?"Yes":"No");
}