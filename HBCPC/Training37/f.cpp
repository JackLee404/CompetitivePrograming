#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

const double EPS = 1e-8;

int n;

double a[N];

double ans[4];

bool debug;

bool check(double r) {
	int cnt = 2, l = 1, idx = 0;

	for (int i = 2; i <= n; i ++) {
		if (a[i] - a[l] > 2 * r) {
			cnt --;
			l = i;

			if (cnt < 0) return false;

			ans[++ idx] = a[l] + (a[i - 1] - a[l]) / 2;	
		}
	}

	return ans[++ idx] = a[l] + (a[n - 1] - a[l]) / 2, true;
}

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	std::sort(a + 1, a + 1 + n);

	double l = 0, r = 1e9;

	while (r - l > EPS) {
		double mid = (l + r) / 2;
		if (check(mid)) r = mid;
		else l = mid;
	}

	printf("%.6lf\n", l);

	int t = 1, idx = 0;

	for (int i = 1; i <= n; i ++) {
		if (a[i] - a[t] > 2 * r) {
			ans[++ idx] = a[t] + (a[i - 1] - a[t]) / 2;	
			t = i;
		}
	}

	ans[++ idx] = a[t] + (a[n] - a[t]) / 2;

	for (int i = 1; i <= 3; i ++) {
		printf("%.6lf ", ans[i]);
	}
}