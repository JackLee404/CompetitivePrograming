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
	if (s - a[h] < n - 1) return puts("1"), 0;

	double res = 1, t1 = s - a[h], t2 = s - 1;

	for (int i = 1; i <= n - 1; i ++) {
		res *= t1 / t2;
		t1 -- , t2 --;
	}

	printf("%.2lf", 1 - res);
}