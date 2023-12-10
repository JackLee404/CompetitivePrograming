#include <bits/stdc++.h>

using i64 = long long;

int f[40][12];

void init() {
	for (int i = 0; i <= 9; i ++) f[1][i] = 1;

	for (int i = 2; i <= 32; i ++) {
		for (int j = 0; j <= 9; j ++) {
			for (int k = j; k <= 9; k ++) {
				f[i][j] += f[i - 1][k];	
			}
		}	
	}
}

int dp(int n) {
	if (!n) return 1;

	std::vector<int> nums;

	while (n) nums.push_back(n % 10), n /= 10;

	int res = 0;
	int last = 0;

	for (int i = (int) nums.size() - 1; i >= 0; i --) {
		int x = nums[i];

		for (int j = last; j < x; j ++) {
			res += f[i + 1][j];
		}

		if (last <= x) last = x;
		else break;

		if (!i) res ++;
	}

	// for (int i = 1; i < nums.size(); i ++) {
	// 	for (int j = 1; j <= 9; j ++) {
	// 		res += f[i][j];
	// 	}	
	// }

	return res;
}

int main() {
	init();

	int l, r;

	while (std::cin >> l >> r) {
		std::cout << dp(r) - dp(l - 1) << "\n";	
	}
}