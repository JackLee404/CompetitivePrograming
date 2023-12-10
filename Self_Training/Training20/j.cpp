#include <bits/stdc++.h>
// #inclue
using i64 = long long;

const int N = 5e5;

i64 a[N], b[N];

std::unordered_map<i64, int> pos;

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		b[i] = a[i];
	}

	std::sort(b + 1,  b + 1 + n);

	for (int i = 1; i <= n; i ++) {
		pos[b[i]] = i;
	}

	i64 ans = 0;

	while (true) {
		bool ok = false;
		for (int i = 2; i <= n; i ++) {
			if (pos[a[i]] < pos[a[i - 1]]) {
				std::swap(a[i], a[i - 1]);
				ans ++;
				ok = true;
				continue;
			}
		}

		if (!ok) {
			break;
		}
	}

	// for (int i = 1; i <= n; i ++) {
	// 	std::cout << pos[a[i]] << " \n"[i == n];
	// }

	std::cout << ans;
}