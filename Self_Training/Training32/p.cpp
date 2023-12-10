#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, l, r;

	std::cin >> n >> l >> r;

	bool ok = true;

	std::vector<int> v1(n + 1);

	for (int i = 1; i <= n; i ++) {
		v1[i] = ((l - 1) / i + 1) * i;
		
		ok = ok && v1[i] <= r;
	}

	puts(ok?"YES":"NO");

	if (ok) {
		for (int i = 1; i <= n; i ++) {
			std::cout << v1[i] << " \n"[i == n];
		}
	}
}

int main() {
	int _; std::cin >> _;	

	while (_ --) {solve();}
}