#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e3 + 10;

int a[N][N], dp[N][N];

int main() {

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			scanf("%d", a[i][j]);
		}
	}

	for (int i = n; i >= 1; i --) {
		for (int j = 1; j <= n; j ++) {
			int res = 0;
			if (i == n) dp[i][j] = a[i][j];
			else {
				for (int k = 1; k <= n; k ++) {
					if (k != j) {

					}
				}
			}
		}
	}
}