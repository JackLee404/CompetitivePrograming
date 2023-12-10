#include <iostream>

using i64 = long long;

const int N = 200;

int n, m, q;

i64 a[N][N], sum[N][N];

void insert(int x1, int y1, int x2, int y2, int k) {
	a[x1][y1] += k;
	a[x2 + 1][y1] -= k;
	a[x1][y2 + 1] -= k;
	a[x2 + 1][y2 + 1] += k;
}

int main() {
	std::cin >> n >> m >> q;

	while(q --) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		insert(x1, y1, x2, y2, 1);
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];

			// std::cout << sum[i][j] << " \n"[j == m]; 
		}
	}

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			ans += (int) (sum[i][j] <= 0);
		}
	}

	std::cout << ans;
}