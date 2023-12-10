#include <iostream>

using i64 = long long;

const int N = 2e5 + 10;

i64 q[N], hh, tt = -1, tot;

int a[N];

int main() {
	i64 n, m, ans = 0;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];


		if(hh <= tt && q[hh] < i - m + 1) tot -= a[q[hh]], hh ++;

		q[++ tt] = i;

		tot += a[i];

		ans = std::max(ans, tot);
	}

	std::cout << ans;
}