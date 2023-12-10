#include <iostream>
#define debug(x) std::cout << x << "\n";

using i64 = long long;

int f[40][40], w[40];

int root[40][40];


void solve(int l, int r) {
	if (l > r) return;
	
	std::cout << root[l][r] << " ";

	if (l >= r) return;

	solve(l, root[l][r] - 1);
	solve(root[l][r] + 1, r);
}

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
		f[i][i] = w[i];
	}

	for (int len = 1; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			if (l == r) {
				root[l][r] = l;
				continue;
			}

			for (int k = l; k < r; k ++) {	
				if (f[l][k - 1] * f[k + 1][r] + w[k] > f[l][r]) {
					root[l][r] = k;
				}

				f[l][r] = std::max(f[l][r], std::max(f[l][k - 1], 1) * std::max(f[k + 1][r], 1) + w[k]);
			}
		}
	}
	
	std::cout << f[1][n] << "\n";
	solve(1, n);
}