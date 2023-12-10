#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int a[N];

int main() {
	int n;

	std::cin >> n;

	i64 ans = 0;

	for(int i = 1; i <= n; i ++) {
		int t = 0;

		for(int j = 0; j < i; j ++) {
			t = t * 10 + 6;
		}

		// std::cout << t << "\n";
		ans += t;
	}		

	std::cout << ans;
}