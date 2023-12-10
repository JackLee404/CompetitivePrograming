#include <iostream>
#include <cstring>
using i64 = long long;

const int N = 1e3 + 10;

int a[N], b[N], c[N];

int f[N][100][100];

int main() {
	int n, m, k;
	std::cin >> n >> m;

	std::cin >> k;
	

	for(int i = 1; i <= k; i ++) {
		std::cin >> a[i] >> b[i] >> c[i];
	}

	memset(f, 0x3f, sizeof f);

	for(int i = 0; i <= k; i ++) {
		f[i][0][0] = 0;
	}

	for(int i = 1; i <= k; i ++) {
		for(int j = 1; j <= n; j ++) {
			for(int l = 1; l <= m; l ++) {
				f[i][j][l] = std::min(f[i - 1][j][l], f[i - 1][std::max(0, j - a[i])][std::max(0, l - b[i])] + c[i]);
			}	
		}
	}

	std::cout << f[k][n][m];
}