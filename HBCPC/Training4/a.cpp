#include <bits/stdc++.h>
#define debug(x) std::cerr << "#debug:" << x << "\n"; 
#define rep(i, j, k) for(int i = j; i <= k; i ++)
#define per(i, j, k) for(int i = j; i >= k; i--)
#define lowbit(x) x&(-x)
using i64 = long long;

/**
 * 题意：
 * 给定字符串a, b，可以替换a中的字符串，但是指定了可以替换的字符集k
 * k的取值范围不超过10
 * 思路：
 * 2^10 = 1024, 我们可以枚举2进制，检查当前2进制是否超过k, 合法的话进行操作算一下贡献
 * 贡献: m = r - l,  则区间贡献为 (m + 1)/ 2 * m
*/

int count(int x) {
	int cnt = 0;
	for(int i = 0; i < 10; i ++) {
		if(x >> i & 1) cnt ++;
	}
	return cnt;
}

int vis[300];

void solve() {
	memset(vis, 0, sizeof vis);
	int n, k, cnt;
	std::cin >> n >> k;

	std::string a, b;
	std::cin >> a >> b;

	std::map<char, int> mp;

	rep(i, 0, n - 1) {
		if(!mp.count(a[i])) mp[a[i]] = cnt ++;
	}

	if(cnt <= k) {
		std::cout << "1\n";
		return;
	}

	int ans = -1;

	for(int S = 0; S < (1ll<<cnt); S ++) {
		if(count(S) > k) continue;
		int res = 0;
		for (int i = 0; i < n; i++ ) {
             int j = i;
             while (j < n && (a[j] == b[j] || (mp[a[j]] && ((S >> mp[a[j]] & 1))))) j++;
             res += (j - i) * (j - i + 1) / 2;
             i = j;
         }
         ans = std::max(ans, res);
	}		

	std::cout << ans << "\n";
}

int main() {
    int _;
    std::cin >> _;
    while(_ --) {
        solve();
    }
}
