#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	i64 x, a = 0, b = 0;
	// x 代表a^b
	std::cin >> x;
	//  k代表a^b>>1 = a与b
	i64 k = x >> 1;

	if(x & 1) {
		puts("-1");
		return;
	}

	for(int i = 0; i <= 32; i ++) {
		int bx = x >> i & 1, bk = k >> i & 1;
		if(bx && bk) {
			puts("-1");
			return;
		} else if(!bk && bx) {
			a += (1ll<<i);
		} else if(bk && !bx){
			a += (1ll<<i);
			b += (1ll<<i);
		}
	}

	std::cout << a << " " << b << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}