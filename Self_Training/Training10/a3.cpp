#include <bits/stdc++.h>


using i64 = long long;

const int N = 1e3 + 10;

int a[N][N], pre[N][N];

void insert(int x1, int y1, int x2, int y2, int c) {
	pre[x1][y1] += c;
	pre[x1][y2 + 1] -= c;
	pre[x2 + 1][y1] -= c;
	pre[x2 + 1][y2 + 1] += c;
}

int main() {
	int n, m, q;

	std::cin >> n >> m >> q;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];		
		}
	}

	while(q --) {
		int x1, y1, x2, y2, c;

		std::cin >> x1 >> y1 >> x2 >> y2 >> c;

		insert(x1, y1, x2, y2, c);
	}

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
			a[i][j] += pre[i][j];		
			std::cout << a[i][j] << " \n"[j == m];
		}
	}
}