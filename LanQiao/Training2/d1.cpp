#include <iostream>
#include <vector>
#include <cstring>

// using i64 = long long;

const int N = 1e4 + 10, M = 1e2 + 10;

int f[M][M];

void solve() {
	int n, m;

	std::cin >> n >> m;

	std::vector<int> v(m + 2);

	for(int i = 1; i <= m; i ++)
		std::cin >> v[i];
	
	v[0] = 0, v[m + 1] = n + 1;

	for(int len = 1; len <= m; len ++) {
		for(int l = 1; len + l - 1 <= m; l ++) {
			int r = len + l - 1;
			if(len == 1) {
				f[l][r] = v[r + 1] - v[l - 1] - 2;
			} else {
				f[l][r] = 0x3f3f3f3f;
				for(int k = l; k <= r; k ++) {
					f[l][r] = std::min(f[l][r], f[l][k - 1] + f[k + 1][r] + v[r + 1] - v[l - 1] - 2);
				}
			}
		}
	}

	std::cout << f[1][m] << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}