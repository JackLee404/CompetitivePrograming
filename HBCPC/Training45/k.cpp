#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int a[N], b[N];

i64 dp[N][3][2];

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];


	for (int i = 1; i <= n; i ++) std::cin >> b[i];


	for (int i = 2; i <= n; i ++) {
		if (b[i]) {
			dp[i - 1][0][0] = dp[i - 1][0][]
		}
	}
}