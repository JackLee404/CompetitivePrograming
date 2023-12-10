#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<int> a(n + 1), b(n + 1);

	std::vector<double> p(n + 1), vec(n + 1), prefix(n + 1);

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i] >> b[i] >> p[i];

		vec[i] = p[i] * (a[i] + b[i]) + (1 - p[i]) * a[i];
	}

	std::sort(vec.begin() + 1, vec.end());

	double ans = 0;

	for (int i = 1; i <= n; i ++) {
		prefix[i] = prefix[i - 1] + vec[i];

		ans += prefix[i];
	}

	printf("%.12lf\n", ans);
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}