#include <iostream>

using i64 = long long;

/*
	假设总人数取100的最优情况
	枚举k
*/

int main() {
	int tot = 100;
	double ans = 1e9;
	int ans2 = 1;

	std::cin >> tot;
	
	for (int k = 1; k <= tot; k ++) {
		double t;

		t = (1.0) * tot / k + ((tot - k % tot) * 0.01) * k;

		if (k % tot) {
			t += (1.0) * 1 + (k % tot) * 0.01 * k;
		}

		if (t <= ans) {
			ans = t, ans2 = k;
		}
		
		// std::cout << t << "\n";
	}

	std::cout << ans2;
}