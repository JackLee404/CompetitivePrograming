#include <iostream>
#include <algorithm>

int exgcd(int a, int b, int &x, int &y) {
	if(!b) {
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

int main() {
	int n;
	std::cin >> n;
	while(n --) {
		int a, b, m;
		std::cin >> a >> b >> m;
		if(b % std::__gcd(a, m) != 0) {
			std::cout << "impossible" << "\n";
		} else {
			int x, y;
			exgcd(a, -m, x, y);
			std::cout << x * (b % m) / d) << "\n";
		}
	}
}