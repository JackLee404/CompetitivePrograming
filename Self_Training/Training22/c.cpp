#include <bits/stdc++.h>


using i64 = long long;

const int N = 3000;

int n, m, k;

int a[N][N];

std::priority_queue<int> q1[N];

int main() {
	std::cin >> n >> m >> k;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int x;
			std::cin >> x;
			q1[i].push(x);
		}
	}

	for (int i = k; i >= 1; i --) {
		i64 ans = 0;
		for (int j = 1; j <= n; j ++) {
			ans += q1[j].top(); q1[j].pop();
		}

		if (i == k) std::cout << ans;
		if (i == 1) std::cout << " " << ans;
	}
}