#include <bits/stdc++.h>

using i64 = long long;

const int N = 10;

int f[N][10];

void init() {
	for (int i = 0; i <= 9; i ++) {
		if (i != 4) {
			f[1][i] = 1;
		}
	}	

	for (int i = 2; i < N; i ++) {
		for (int j = 0; j <= 9; j ++) {
			if (j == 4) continue;
			for (int k = 0; k <= 9; k ++) {
				if (k == 4 || j == 6 && k == 2) continue;	
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

		for (int j = 0; j < x; j ++) {
			if (j == 4 || last == 6 && j == 2) continue;
			
			res += f[i + 1][j];
		}

		if (x == 4 || last == 6 && x == 2) break;
        
        last = x;
        
		if (!i) res ++;
	}

	return res;
}

int main() {
	init();			

	int l, r;

	while (std::cin >> l >> r, l && r) {
		std::cout << dp(r) - dp(l - 1) << "\n";
	}
}