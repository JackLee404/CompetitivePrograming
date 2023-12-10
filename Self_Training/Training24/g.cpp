#include <bits/stdc++.h>

using i64 = long long;

bool col[100010], row[100010];

int main() {
	int n, m, q;

	std::cin >> n >> m >> q;

	while (q --) {
		int t, c;

		std::cin >> t >> c;

		if (t == 1) {
			if (!col[c])
				m --, col[c] = true;
		} else {
			if (!row[c])
				n --, row[c] = true;
		}
	}

	std::cout << n * m;
}