#include <bits/stdc++.h>
// #inclue
using i64 = long long;

const int N = 5e5;

int n, a[N], dp[N], cnt;

int pre[N];

std::vector<int> g[N];

void out(int s) {
	if (s == 0) {
		// std::cout << s;
		// g[cnt].push_back(s);
		return;
	}

	if (n - s + 1) {
		std::cout << " ";
	}

	std::cout << n - s + 1;

	out(pre[s]);
}

int main() {
	std::cin >> n;

	for (int i = 0; i <= n; i ++) {
		std::cin >> a[i];
	}

	std::reverse(a + 0, a + 2 + n);

// 	for (int i = 0; i <= n + 1; i ++) {
// 		std::cout << a[i] << " \n"[i == n + 1];
// 	}

	dp[0] = a[0];

	for (int i = 1; i <= n + 1; i ++) {
		dp[i] = dp[i - 1] + a[i];
		
		pre[i] = i - 1;

		if (i - 2 >= 0) {
			if (dp[i] > dp[i - 2] + a[i]) {
				pre[i] = i - 2;
			}
			dp[i] = std::min(dp[i], dp[i - 2] + a[i]);
		}
		
		if (i - 3 >= 0) {
			if (dp[i] > dp[i - 3] + a[i]) {
				pre[i] = i - 3;
			}
			dp[i] = std::min(dp[i], dp[i - 3] + a[i]);
		}

		
	}

	std::cout << dp[n + 1] << "\n";

	out(n + 1);
}