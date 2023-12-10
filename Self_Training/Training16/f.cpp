#include <iostream>

using i64 = long long;

const int N = 600;

i64 a[N][N];
int n, m, k;

i64 get(int x1, int y1, int x2, int y2) {
	return a[x2][y2] - a[x1 - 1][y2] - a[x2][y1 - 1] + a[x1 - 1][y1 - 1];
}

int main() {
	
	
	std::cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			std::cin >> a[i][j];
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
		}
	}

	i64 ans = 0;


	for (int len = 1; len <= n; len++) {
		for (int x1 = 1; x1 + len - 1 <= n; x1++) {
			int x2 = x1 + len - 1;

			for(int y1 = 1, y2 = 1; y1 <= m; y1 ++) {

				while(get(x1, y1, x2, y2) <= k  && y2 <= m) y2 ++;

				ans += (y2 - y1);
			}
		}
	}

	std::cout << ans;
}