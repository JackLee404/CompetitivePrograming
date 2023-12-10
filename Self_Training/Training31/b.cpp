#include <iostream>

using i64 = long long;

const int N = 100;

int n, m;

int a[N][N];

bool b[N][N];

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
			// y x z
			if (j != 1) {
				int x = a[i][j], y = a[i][j - 1];
				b[x][y] = b[y][x] = true;
				if (j != n) {
					int z = a[i][j + 1];
					b[x][z] = b[z][x] = true;
				}
			}
		}
	}

	// puts("??");

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (!b[i][j]) res ++;
		}
	}

	std::cout << res;
}