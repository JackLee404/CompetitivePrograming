#include <bits/stdc++.h>

using i64 = long long;

int exgcd(int a, int b, int &x, int &y) {
	if (!b) return x = 1, y = 0, a;
	int d = exgcd(b, a % b, x, y);
	int tmp = x;
	return x = y, y = tmp - a / b * y, d;
}

void solve() {
	int a, b, x, x1, y1;

	std::cin >> a >> b >> x;

	if (std::__gcd(a, b) != x) {
		return puts("-1"), void(0);
	}

	exgcd(a, b, x1, y1);

	std::cout << 
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();	
	}		
}