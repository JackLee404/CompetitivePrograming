#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e5 + 10;

int a[N], b[N], cnt1, cnt2;

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		a[++ cnt1] = i;
	}

	int k = n;

	while (cnt1 > 2) {
		for (int i = 1; i <= cnt1; i ++) {
			if (i % 2 != 0) {
				continue;
			}
			b[++ cnt2] = a[i];
		}
		cnt1 = cnt2;
		cnt2 = 0;
		memcpy(a, b, sizeof b);
	}

	std::cout << a[2];
}