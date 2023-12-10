#include <bits/stdc++.h>

using i64 = long long;

double a[1000];

int main() {
	int n;
	std::cin >> n;
	double ans = 0;
	for (int i = 1; i <= n; i ++) {
		double x;

		std::cin >> x;

		ans += x;
	}

	ans = ans * 100 / n;

	printf("%.2lf%%", ans);
}