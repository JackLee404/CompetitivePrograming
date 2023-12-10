#include <iostream>
#include <algorithm>
#include <cstring>

using i64 = long long;

const int N = 200, M = 10010;

struct node {
	int e, l, s;
}a[N];

int f[N];

int main() {
	int _;
	std::cin >> _;

	for(int i = 1; i <= _; i ++) {
		int n, m;
		std::cin >> n;

		memset(f, -0x3f, sizeof f);

		f[0] = 0;
		m = 0;

		for(int i = 1; i <= n; i ++) {
			std::cin >> a[i].s >> a[i].e >> a[i].l;
			m += a[i].s;
		}

		std::sort(a + 1, a + 1 + n, [](node &a, node &b) {
			return b.l * a.s <  a.l * b.s;
		});

		for(int i = 1; i <= n; i ++) {
			for(int j = m; j >= a[i].s; j --) {
				f[j] = std::max(f[j], f[j - a[i].s] + std::max(0, a[i].e - (j - a[i].s) * a[i].l));
			}	
		}

		int ans = 0;

		for(int i = 0; i <= m; i ++) {
			ans = std::max(ans, f[i]);
		}

		printf("Case %d: %d\n", i, ans);
	}
}