#include <bits/stdc++.h>

using i64 = long long;

const int N = 300, M = 1e5 + 10;

int n, k;

int a[N];

bool st[M];

void init() {
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			for (int k = j + 1; k <= n; k ++) {
				for (int l = k + 1; l <= n; l ++) {
					int x = a[i] + a[j] + a[k] + a[l];


					if (x % 4 == 0) {
						st[x / 4] = true;
					}
				}
			}
		}
	}
}

int main() {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
	}

	init();

	while (k --) {
		bool ok = true;

		int t;

		std::cin >> t;

		for (int i = 1; i <= t; i ++) {
			int x;

			std::cin >> x;

			if (st[x]) continue;

			ok = false;
		}

		puts(ok? "Yes": "No");
	}
}