#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int main() {
	int n;

	while(std::cin >> n) {
		std::vector<int> a(n + 1), sum(n + 1), pre(n + 2);

		for(int i = 1; i <= n; i ++) {
			std::cin >> a[i];

			// sum[i] = a[i] + sum[i - 1];
		}

		for(int i = n; i >= 1; i --) {
			if(i == n) pre[i] = a[i];
			else pre[i] = std::min(pre[i + 1], a[i]);
		}

		i64 ans = -0x3f3f3f3f;

		for(int i = 1; i < n; i ++) {
			ans = std::max(ans, 1LL * a[i] - pre[i + 1]);
		}

		std::cout << ans << "\n";
	}
}