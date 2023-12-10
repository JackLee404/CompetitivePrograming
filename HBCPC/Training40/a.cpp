#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int n;

int a[N];

std::vector<std::pair<int, int>> v1;

int main() {
	std::cin >> n;

	bool ok = false;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		if (v1.empty()) {
			v1.push_back({a[i] + 15, a[i] + 44});
			ok = false;
		} else {
			if (a[i] < v1.back().first) continue;
			
			if (a[i] > v1.back().second) {
				v1.push_back({a[i] + 15, a[i] + 44});
				ok = false;
				continue;
			}

			if (!ok) {
				ok = true;
				v1.back().second += 15;
			}
		}
	}

	for (auto &x: v1) {
		std::cout << x.first << " " << x.second << "\n";
	}
}