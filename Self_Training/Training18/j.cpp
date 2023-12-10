#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int f[N];

int main() {
	int n;

	std::cin >> n;

	int ans = 0;

	for (int i = 1; i <= n; i ++) {
		int x = i, t = 1;

		std::vector<int> p2;

		for (int k = 2; k <= i; k ++) {
			int cnt = 0;

			while (x) {
				x /= k;
				cnt ++;
			}
			if (cnt) p2.push_back(cnt);

			// std::cou
		}
		
		for (auto v: p2) {
			t *= (v + 1);
		}

		std::cout << t << " \n"[i == n];
	}

	std::cout << ans;
}