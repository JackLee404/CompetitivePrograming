#include <bits/stdc++.h>

using i64 = long long;

const int N = 11;


i64 f[N][N], g[N][N];

i64 power[N];

void init() {
	power[0] = 1;

	for (int i = 1; i <= 9; i ++) power[i] = power[i - 1] * 10;

	// f[i][j] 表示含有前导0, 0~(i个9)
	for (int i = 0; i <= 9; i ++) f[1][i] = 1;

	for (int i = 2; i <= 9; i ++) {
		for (int j = 0; j <= 9; j ++) {
			f[i][j] = 10 * f[i - 1][j] + power[i - 1];
		}
	}

	// g[i][j] 表示不含有前导0, 0~(i个9)

	// g[i][j] = 9 * f[i - 1][j] + power[i - 1] + g[i - 1][j];

	for (int i = 1; i <= 9; i ++) g[1][i] = 1;

	for (int i = 2; i <= 9; i ++) {
		g[i][0] = 9 * f[i - 1][0] + g[i - 1][0];
		for (int j = 1; j <= 9; j ++) {
			g[i][j] = 9 * f[i - 1][j] + power[i - 1] + g[i - 1][j];
		}
	}
}

std::vector<int> dp(int n) {
	std::vector<int> res(10, 0), last(10, 0);

	if (!n) return res;

	std::vector<int> nums;

	while (n) nums.push_back(n % 10), n /= 10;

	for (int i = 0; i <= 9; i ++) res[i] += g[(int) nums.size() - 1][i];

	for (int i = (int) nums.size() - 1; i >= 0; i --) {
		int x = nums[i];

		for (int j = (i == nums.size() - 1); j < x; j ++) {
			for (int k = 0; k <= 9; k ++) {
				res[k] += last[k] * power[i];
			}

			res[j] += power[i];

			for (int k = 0; k <= 9; k ++) {
				res[k] += f[i][k];					
			}
		}

		last[x] ++;

		if (!i) {
			for (int k = 0; k <= 9; k ++) {
				res[k] += last[k];
			}
		}
	}

	return res;
}

int main() {
	init();

	// for (int i = 0; i <= 9; i ++) {
	// 	std::cout << f[2][i] << "\n";
	// }

	int l, r;
	
	while (std::cin >> l >> r, l || r) {
		if (l > r) std::swap(l, r);

		std::vector<int> v1 = dp(r);
		
		std::vector<int> v2 = dp(l - 1);

		for (int i = 0; i <= 9; i ++) {
			std::cout << v1[i] - v2[i] << " \n"[i == 9];
		}
	}
}