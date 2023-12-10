#include <bits/stdc++.h>

using i64 = long long;

using namespace std;

void solve() {
	int hh, tt, x;

	scanf("%d:%d %d-%d", &hh, &tt, &x, &x);

	// std::cout << hh << " " << tt << " " << x << "\n";

	if (x != 1) {
		puts("05:05");
		return;
	} else {
		tt += 5;

		if (tt >= 60) {
			hh ++;
			tt %= 60;
		}
	}

	printf("%02d:%02d\n", hh, tt);
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}