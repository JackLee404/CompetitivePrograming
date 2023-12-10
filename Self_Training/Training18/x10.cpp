#include <iostream>
#include <vector>

using i64 = long long;

const int mod = 1e8 + 7;

const int N = 1004;

i64 n, s, a, b;

i64 f[N][N];

i64 m(i64 x) {
	return (x % n + n) % n;
}

int main() {
	
	
	std::cin >> n >> s >> a >> b;
	
	f[0][0] = 1;

	for (int i = 0; i < n - 1; i ++) {
		for (int j = 0; j < n; j ++) {
			f[i + 1][m(j + (n - i - 1) * a)] += f[i][j];
			f[i + 1][m(j + (n - i - 1) * a)] %= mod;
			f[i + 1][m(j - (n - i - 1) * b)] += f[i][j];
			f[i + 1][m(j - (n - i - 1) * b)] %= mod;
		}
	}

	std::cout << f[n - 1][m(s)];
}