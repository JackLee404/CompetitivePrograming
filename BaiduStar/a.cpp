#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int a[N];

std::vector<int> G[N];

int main() {
	int n, p;

	std::cin >> n >> p;

	i64 ans = 0;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		G[a[i]].push_back(i);
	}

	for (int i = 1; i <= 1e6; i ++) {
		if (G[i].size() <= 1) continue;

		// std::cout << i << "---\n";
		
		std::vector<int> &v1 = G[i];

		// int cnt = 1, t = v1[0];

		bool ok = false;

		for (int i = 1; i < v1.size(); i ++) {
			// std::cout << t << "\n";
			if (v1[i] - v1[i - 1] <= p) {
				// if (cnt % 2 == 0) ans ^= t;
				// t = cnt = 0;
				ok = true;
				break;
			}

			// t ^= v1[i], cnt ++;
		}

		if (ok) {
			ans ^= i;
		}

		// std::cout << cnt << " " <<  t << "\n";

		// if (cnt > 1 && cnt % 2 == 0) ans ^= t;
	}

	std::cout << ans;
}