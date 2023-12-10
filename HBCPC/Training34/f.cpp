#include <bits/stdc++.h>

using i64 = long long;

int n;

int main() {
	std::cin >> n;

	int ans = 0;

	for (int i = 2; i <= n / i; i ++) {
		if (n % i == 0) {
			while (n % i == 0) {
				n /= i;
			}
			ans += i;
		}		
	}

	if (n) ans += n;

	std::cout << ans;
}