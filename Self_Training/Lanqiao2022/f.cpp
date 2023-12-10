#include <iostream>

using i64 = long long;

const int N = 1e3 + 10;

int n, m, k;

int a[N][N];

i64 sum[N][N];

i64 calc(int x1, int y1, int x2, int y2) {
	if (y1 > y2) {
		return -1;
	}
	i64 k = sum[x2][y2] - sum[x2][y1 - 1] - sum[x1 - 1][y2] + sum[x1 - 1][y1 - 1];
	return k;
}

int main() {
	std::cin >> n >> m >> k;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];

			sum[i][j] = a[i][j] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
		}
	}

	i64 ans = 0;

	for(int h = 1; h <= n; h ++) {
		for(int r = 1; r <= n; r ++) {
			int x1 = r, x2 = r + h - 1;

			if(x2 > n) break;

			for(int y1 = 1, y2 = 1; y1 <= m; y1 ++) {
				// std::cout << (calc(x1, y1, x2, y2)) << "\n";

				while(calc(x1, y1, x2, y2) <= k  && y2 <= m) y2 ++;

				
								
				ans += (y2 - y1);
			}
		}
	}

	std::cout << ans;
}