#include <bits/stdc++.h>
#include <cstring>
#define rep(i, j, k) for(i64 i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i --)
using i64 = long long;

/*
	完全背包
	dp[i][j] = max(dp[i - 1][j], dp[i][j - v[i]] + w[i]);
*/

const int N = 3e3 + 5, MAX = 2e6 + 10;

i64 dp[MAX], v[N];

int main() {	
    int n, m;
    std::cin >> m >> n;
    
    rep(i, 1, n) {
        std::cin >> v[i];
    }

    memset(dp, 0x3f, sizeof dp);
    
    dp[0] = 0;

	rep(i, 1, n) {
		rep(j, v[i], MAX) {
			dp[j] = std::min(dp[j], dp[j - v[i]] + 1);
			// if(dp[j] > m) {
			// 	break;
			// }
		}
	}

	int ans = 0;

	for(int i = 1; i <= MAX; i ++) {
		if(dp[i] > m) {
			break;
		}
		ans ++;
	}

	std::cout << ans;
}