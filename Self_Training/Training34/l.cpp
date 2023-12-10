#include <bits/stdc++.h>

using i64 = long long;

const int N = 110;

int n;

int d1[N][N], d[N][N];

void solve() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cin >> d[i][j];	

			d1[i][j] = d[i][j];
		}
	}


	std::map<std::pair<int, int>, bool> mp;

	int cnt = 0;

	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				if (i == j || k == i || k == j) continue;
				if (d1[i][k] + d1[k][j] == d1[i][j]) {
					mp[{i, j}] = mp[{j, i}] = true;
					// std::cout << i << " " << j << " " << k << "\n";
				}
			}
		}				
	}


	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (mp[{i, j}]) d[i][j] = -1;
			if (d[i][j] != -1) cnt ++;
		}
	}

	std::cout << cnt << "\n";

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (d[i][j] != -1) {
				std::cout << i << " " << j << "\n";
			}
		}
	}
}

int main() {

	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}