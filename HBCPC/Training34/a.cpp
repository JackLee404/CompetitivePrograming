#include <bits/stdc++.h>

using i64 = long long;

const int N = 31;

int K, B;

int f[N][N];

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j) f[i][j] = 1;
			else f[i][j] = f[i - 1][j - 1] + f[i - 1][j];
		}
	}	
}

int dp(int n) {
	if (!n) return 0;

	std::vector<int> nums;

	while (n) nums.push_back(n % B), n /= B;

	int res = 0;
	int last = 0;

	for (int i = (int) nums.size() - 1; i >= 0; i --) {
		int x = nums[i];
		if (x) { // 求左边分支的个数
			res += f[i][K - last];
			if (x > 1) {
				if (K - last - 1 >= 0)
					res += f[i][K - last - 1];
				break;
			} else {
				last ++;
				if (last > K) break;
			}
		}
		if (!i && last == K) res ++; // 考虑最后一位是否为0
	}
	std::cout << last << "\n";
	return res;
}

int main() {
	init();

	int l, r;

	std::cin >> l >> r >> K >> B;


	std::cout << dp(r) - dp(l - 1);
}