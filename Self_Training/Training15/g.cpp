#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

i64 dp[N];

int main() {
	dp[1] = 1;

	for(int i = 2; i <= 40; i ++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		int m;

		std::cin >> m;
        
        if(m == 1) {
            std::cout << 0 << "\n";
            continue;
        }

		std::cout << dp[m] << "\n";
	}
}