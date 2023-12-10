#include <iostream>
#include <algorithm>
#include <cstring>


using i64 = long long;

const int mod = 1e9 + 7, N = 5e3 + 100;

int f[N][N], n;

int solve(std::string t) {
	memset(f, 0, sizeof f);

	f[0][0] = 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= n; j ++) {
			if(t[i] == '(') {
				f[i][j] = f[i - 1][j - 1];
			} else {
				if(j == 1)
					f[i][0] = ((i64)f[i - 1][0] + f[i - 1][1]) % mod;
				f[i][j] = ((i64)f[i - 1][j + 1] + f[i][j - 1]) % mod;
			}
		}
	}

	for(int i = 0; i <= n; i ++)
		if(f[n][i])
			return f[n][i];
	return -1;
}

int main() {
	std::string t;

	std::cin >> t;

	n = t.size();

	t = " " + t;

	i64 k1 = solve(t);

	std::reverse(t.begin() + 1, t.end());
	
	for(int i = 1; i <= n; i ++) {
		char &x = t[i];

		x = (x == ')'?'(':')');
	}

	i64 k2 = solve(t);

	std::cout << (k1 * k2) % mod;
}