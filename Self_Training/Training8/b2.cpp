#include <iostream>
#include <algorithm>

using i64 = long long;

const int N = 100;

int a[N], f[N][N];

int main() {
	int k, n;
	std::cin >> k >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::sort(a + 1, a + 1 + n);
	f[0][0] = 1;


	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= k; j ++) {
			f[i][j] = f[i - 1][j] + f[i][j - 1];
		}
	}
}