#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	int a = 1;

	for(int i = 2; i <= n / i; i ++) {
		if(n % i == 0) {
			a = n / i;
			break;
		}
	}
	
	std::cout << a << " " << n - a << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}