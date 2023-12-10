#include <bits/stdc++.h>

using i64 = long long;

int f[20][20];

void init() {
	for (int i = 0; i <= 9; i ++) f[1][i] = 1;

	for (int i = 2; i <= 10; i ++) {
		for (int j = 0; j <= 9; j ++) {
			for (int k = 0; k <= 9; k ++) {
				if (std::abs(j - k) >= 2)
					f[i][j] += f[i - 1][k];
			}
		}
	}
}

int dp(int n) {
	if (!n) return 0;	

	std::vector<int> nums;

	while (n) nums.push_back(n % 10), n /= 10;

	int res = 0;
	int last = -2;

	for (int i = (int) nums.size() - 1; i >= 0; i --) {
		int x = nums[i];

		for (int j = (i == (int) nums.size() - 1); j < x; j ++) {
			if (std::abs(j - last) >= 2)
				res += f[i + 1][j];
		}

		if (std::abs(last - x) >= 2) last = x;
		else break;

		if (!i) res ++;
	}

	// 特殊处理小于n位数的windy数
	for (int i = 1; i < nums.size(); i ++) {
		for (int j = 1; j <= 9; j ++) {
			res += f[i][j];	
		}
	}

	return res;
}

int main() {
	int l, r;

	std::cin >> l >> r;
	std::cout << dp(r) - dp(l - 1) << "\n";
}