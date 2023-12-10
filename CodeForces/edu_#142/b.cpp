#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int a, b, c, d;
	std::cin >> a >> b >> c >> d;

	int ans = a;

	if(!a) {
		std::cout << 1 << "\n";
	} else {
		int k = std::min(b, c);		
		ans += 2 * k;
		int m = abs(b - c);

		if(m > a) {
			std::cout << ans + a + 1 << "\n";
		} else {
			ans += m;
			if(d > a - m) {
				std::cout << ans + (a - m) + 1<< "\n";
			} else {
				std::cout << ans + d << "\n";
			}
		}
	}
}

int main() {
	int _;
	std::cin >> _;
	while(_ --){
		solve();
	}
}