#include <bits/stdc++.h>

using i64 = long long;

bool check(int x) {
	int cnt = 0;

	for (i64 i = 2; i <= x / i; i ++) {
		while (x % i == 0) {
			x /= i;
			cnt ++;
		}
	}

	if (x > 1) cnt ++;

	return cnt == 12;
}

int main() {
	i64 ans = 0;

	for (int i = 2333333; i <= 23333333; i ++) {
		if (check(i)) {
			ans ++;
		}
	}
	std::cout << ans;
}