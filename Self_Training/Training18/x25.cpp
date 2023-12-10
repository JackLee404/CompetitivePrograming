#include <iostream>
#include <algorithm>
#include <cstring>

using i64 = long long;

const int N = 200;

int cnt = 0, a[N], b[N];

bool st[N];

void solve() {
	memset(st, false, sizeof st);

	int n, c1, c2, ans = 0;

	std::cin >> n >> c1 >> c2;

	if (c2 < c1) std::swap(c1, c2);

	for (int i = 1; i <= n; i ++)
		std::cin >> a[i];

	std::sort(a + 1, a + 1 + n, std::greater<int>());	

	int p1, p2;	

	while (true) {
		p1 = 0, p2 = 0;
		for (int i = 1; i <= n; i ++) {
			if (st[i]) continue;
			if (p1 + a[i] <= c2) {
				st[i] = true;
				p1 += a[i];
			} else if (p2 + a[i] <= c1) {
				p2 += a[i];
				st[i] = true;
			}
		}
		if (!p1 && !p2) break;
		ans ++;
	}
	printf("Scenario #%d:\n", ++ cnt);
	std::cout << ans << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}