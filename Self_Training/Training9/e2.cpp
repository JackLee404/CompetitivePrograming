#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int a[N][N];

i64 pre[N][N];

int main() {
	int n, m, q;

	std::cin >> n >> m >> q;


	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
			pre[i][j] = pre[i - 1][j] + pre[i][j - 1] + a[i][j] - pre[i - 1][j - 1];
		}
	}	

	while(q --) {
		int x1, x2, y1, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		int k = pre[x2][y2] - pre[x1 - 1][y2] - pre[x2][y1 - 1] + pre[x1 + 1][y1 + 1];


		std::cout << k << "\n";
	}
}