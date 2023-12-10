#include <bits/stdc++.h>
#include <numeric>

using i64 = long long;

const int N = 1e3 + 10;

int n, m, h, s;

int a[N];

int main() {
	std::cin >> n >> m >> h;

	for (int i = 1; i <= m; i ++) {
		std::cin >> a[i], s += a[i];
	}

	if (s < n) return puts("-1"), 0;

	double res = 0, t1 = s - a[h], t2 = s - 1;

	for (int i = 1; i <= s - n + 1; i ++) {
		if (t1 < s - a[h] - n + 1) t1 = 1;

		res += t1 / t2;
	}

	printf("%.6lf", 1 - res);
}