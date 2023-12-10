#include <iostream>
#include <cmath>
#include <cstring>
#define len(x) (int)log10(x) + 1
using i64 = long long;

const int N = 1e5 + 10;

i64 a[N];

i64 b[11][N];

i64 ans = 0;

int main() {
	i64 n, k;

	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	for (int i = 1; i <= n; i ++) {
		ans += b[len(a[i])][(k - a[i] % k) % k];
		i64 t = 10;
		for (int j = 1; j <= 10; j ++) {
			b[j][(a[i] % k * t) % k] ++;
			t *= 10;
			t %= k;
		}	
	}

	memset(b, 0, sizeof b);

	for (int i = n; i >= 1; i --) {
		i64 t = 10;
		ans += b[len(a[i])][(k - a[i] % k) % k];
		for (int j = 1; j <= 10; j ++) {
			b[j][(a[i] % k * t) % k] ++;
			t *= 10;
			t %= k;
		}
	}

	std::cout << ans;
}