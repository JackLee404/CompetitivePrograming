#include <iostream>

using i64 = long long;

const int N = 1e3 + 10, mod = 1e9 + 7;

int dp[N], v[N], w[N], cnt[N];

int main() {
	int n, m;

	std::cin >> n >> m;


	for(int i = 1; i <= n; i ++) std::cin >> v[i] >> w[i];

    // for(int i = 0; i <= m; i ++) cnt[i] = 1;
    
    cnt[0] = 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= v[i]; j --) {
		    dp[j] = std::max(dp[j], dp[j - v[i]] + w[i]);
		    if(dp[j - v[i]] + w[i] > dp[j]) {
		        cnt[j] = cnt[j - v[i]];
		    } else if(dp[j] == dp[j - v[i]] + w[i]) {
		        cnt[j] = ((i64)cnt[j] + cnt[j - v[i]]) % mod;
		    }
		}
	}

	std::cout << cnt[m];
}