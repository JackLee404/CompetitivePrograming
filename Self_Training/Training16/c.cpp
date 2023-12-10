#include <iostream>
#include <cstring>
#include <numeric>

using i64 = long long;

const int N = 1000;

int f[N][N], f2[N][N], a[N], sum[N];

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		std::cin >> a[i];
		a[n + i] = a[i];
	}

	// n *= 2;

	for (int i = 1; i <= 2 * n; i++) {
		sum[i] = sum[i - 1] + a[i];
	}

	int ans = 1e9, ans2 = -1e9;

	for (int len = 1; len <= n; len++) {
		for (int l = 1; len + l - 1 <= n * 2; l++) {
			int r = len + l - 1;
			if (len == 1) {
				f[l][r] = f2[l][r] = 0;
				continue;
			}

			f[l][r] = 1e9;
			f2[l][r] = -1e9;
			
			for (int k = l; k < r; k++) {
				f[l][r] = std::min(f[l][r], f[l][k] + f[k + 1][r] + sum[r] - sum[l - 1]);
				f2[l][r] = std::max(f2[l][r], f2[l][k] + f2[k + 1][r] + sum[r] - sum[l - 1]);
			}

			if (len == n) {
				ans = std::min(f[l][r], ans);
				ans2 = std::max(f2[l][r], ans2);
			}
		}
	}

	// for (int i = 1; i <= n; i++) {
    //     ans = std::min(f[i][i + n - 1], ans);
    //     ans2 = std::max(f2[i][i + n - 1], ans2);
	// }

	std::cout << ans << "\n" << ans2;
}