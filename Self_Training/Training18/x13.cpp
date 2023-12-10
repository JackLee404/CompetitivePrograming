#include <iostream>
#define debug(x) std::cout << x << "\n";

using i64 = long long;

const int N = 1e3 + 10;

int cnt;

struct node {
	int l, r;
} a[N];

i64 f[N][N];

int main() {
	int n;
	
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x;
		std::cin >> x;
		
		a[i].l = x;

		if(i > 1) {
			a[i - 1].r = x;
			if (i == n) a[i].r = a[1].l;
		}
	}

	for (int i = 1; i <= n; i ++) {
		a[n + i] = a[i];
	}

	i64 ans = 0;

	for (int len = 1; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= 2 * n; l ++) {
			int r = l + len - 1;
			// std::cout << l << " " << r << "\n";
			// break;
			for (int k = l; k < r; k ++) {
				// puts("hello");
				if(l == r) {
					f[l][r] = 0;
					continue;
				}
				
				 
				f[l][r] = std::max(f[l][r], f[l][k] + f[k + 1][r] + a[l].l * a[k].r * a[r].r);

				// std::cout << l << " " << r << "\n";
				// std::cout << f[l][r] << "\n";
			}

			if (len == n) {
				ans = std::max(ans, f[l][r]);
			}
		}
	}

	// debug(f[4][5]);

	std::cout << ans;
}