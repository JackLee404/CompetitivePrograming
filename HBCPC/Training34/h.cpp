#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>

#define PI acos(-1.0)

using i64 = long long;

const double EPS = 1e-5;

const int N = 1e4 + 10;

int n, f;

int a[N];

bool check(double x) {
	int cnt = 0;
	for (int i = 1; i <= n; i ++) {
		cnt += ((a[i] * a[i] * 1.0 * PI) / x);
	}
	return cnt >= f + 1;
}

void solve() {
	std::cin >> n >> f;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];

	}

	double l = 0, r = pow(*std::max_element(a + 1, a + 1 + n), 2) * PI;

	while ((r - l) > EPS) {
		double mid = (l + r) / 2;
		if (check(mid)) l = mid;
		else r = mid;
	}	

	std::cout << std::fixed << std::setprecision(4) << l << "\n";
}


int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}	
}