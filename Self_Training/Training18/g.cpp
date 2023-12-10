#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int n, f[N];

int main() {
	f[1] = 1;

	std::cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		int x = i, t = 1;
		for (int k = 1; k <= i / k; k ++) {
			int cnt = 0;
			while (x % k == 0) x /= k, cnt ++;
		}	
		if (x > 1) t *= 2;
		ans += (t % 2 != 0);
	}

	std::cout << ans;
}