#include <bits/stdc++.h>

using i64 = long long;

const int N = 12, M = 110;

int P;
int f[N][10][M];

int mod(int x, int y) {
	return (x % y + y) % y;
}

void init() {
	memset(f, 0, sizeof f);
	
	for (int i = 0; i <= 9; i ++) f[1][i][i % P] ++;

	for (int i = 2; i < N; i ++) {
		for (int j = 0; j <= 9; j ++) {
			for (int k = 0; k < P; k ++) {
				for (int x = 0; x <= 9; x ++) {
					f[i][j][k] += f[i - 1][x][mod(k - j, P)];
				}
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

		for (int j = 0; j < x; j ++) {
			res += f[i + 1][j][mod(-last, P)];
		}

		last += x;

		if (!i && last % P == 0) res ++;
	}

	return res;
}

int main() {
	int l, r;

	while (std::cin >> l >> r >> P) {
		init();
 		std::cout << dp(r) - dp(l - 1) << "\n";
	}
}