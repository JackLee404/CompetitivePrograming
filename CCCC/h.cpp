#include <bits/stdc++.h>

using i64 = long long;

i64 t;

int calc(i64 x) {
	int res = 0;
	while (x) {
		res += x % 10;
		x /= 10;
	}
	return res;
}

int main() {
	int n;
	
	std::cin >> n;
	
	while (n --) {
		i64 a, b;
		
		std::cin >> a >> b;
		
		int k1 = calc(a), k2 = calc(b);
		
		if (a % k2 == 0 && b % k1 == 0) {
			puts(a>b?"A":"B");
		} else if (a % k2 == 0) {
			puts("A");
		} else if (b % k1 == 0) {
			puts("B");
		} else {
			puts(a>b?"A":"B");
		}
	}
}