#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int a[N];

int main() {
	i64 x, y;

	while(std::cin >> x >> y) {
        if(!x && !y) break;
        
		if(x > y) std::swap(x, y);

		int k = x;

		while((x % k) != 0 || (y % k) != 0) {
			k --;
		}

		std::cout << (x * y) / (k * k) << "\n";
	}
}