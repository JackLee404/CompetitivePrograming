#include <iostream>

using i64 = long long;

const int N = 1010;

int sum[N][N], a[N][N];

int main() {
	int n, m;
	

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf("%d", &a[i][j]);
			sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + a[i][j];
		}
	}

	int q;

	std::cin >> q;

	while (q --) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		printf("%d\n", sum[x2][y2] + sum[x1 - 1][y1 - 1] - sum[x1 - 1][y2] - sum[x2][y1 - 1]);
	}
}