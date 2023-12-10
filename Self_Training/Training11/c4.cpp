#include <bits/stdc++.h>

using i64 = long long;

const int N = 600;

std::vector<std::pair<int, int>> v1;

int a[N][N];

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

int main() {
	int m, n, k;

	std::cin >> m >> n >> k;

	for(int i = 1; i <= m; i ++) {
		for(int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
			v1.push_back({i, j});
		}
	}

	std::sort(v1.begin(), v1.end(), [](std::pair<int, int> a1, std::pair<int, int> b1) {
		int x1 = a1.first, y1 = a1.second, x2 = b1.first, y2 = b1.second;
		return a[x1][y1] > a[x2][y2];
	});

	int ans = 0, tot = 1;
	int lx, ly;

	lx = 1, ly = v1[0].second;

	for(int i = 0; i < v1.size(); i ++) {
		int &x = v1[i].first, &y = v1[i].second;
		
		// std::cout << a[x][y] << "\n";
		
		tot += dist(x, y, lx, ly) + 1;

		if(tot + dist(x, y, 1, y) + 1 > k) break;

		ans += a[x][y];

		// std::cout << tot << "\n";
		

		lx = x, ly = y;
	}

	std::cout << ans;
}