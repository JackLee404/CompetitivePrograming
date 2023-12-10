#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define sz(x) (int)x.size()
#define OUT(x) FOR(i, j, sz(x) - 1) std::cout << x[i] << " \n"[j == sz(x) - 1];
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 1e5 + 10, M = 2e4 + 5e3 + 10;

struct node{
	int t, h, f;
}a[N];

int dp[2][M];

/*
	dp[i][j] 表示考虑前i个物品，物品高度为j时，最多可以活多长时间
	可以选择 堆积 和 吃掉
	dp[i][j] = max(dp[i - 1][j] + v, dp[i - 1][j - h]);
*/

int main() {
	int d, g, h;

	std::cin >> d >> g;

	for(int i = 1; i <= g; i ++) {
		std::cin >> a[i].t >> a[i].f >> a[i].h;
	}

	std::sort(a + 1, a + 1 + g, [](node &a, node & b) {
		return a.t < b.t;
	});

	// FOR(i, 1, g) {
	// 	std::cout << a[i].t << " " << a[i].h << " " << a[i].f << "\n";
	// }


	memset(dp, 0xc0, sizeof dp);

	dp[0][0] = 10;

	int ans = 0;

	for(int i = 1; i <= g; i ++) {
		int pre = (i - 1) & 1, cur = i & 1;
		memset(dp[cur], 0xc0, sizeof dp[cur]);
		for(int j = d; j >= 0; j --) {
			if(dp[pre][j] < a[i].t) continue;
			if(j + a[i].h >= d) return std::cout << a[i].t, 0;
			dp[cur][j + a[i].h] = std::max(dp[cur][j + a[i].h], dp[pre][j]);
			dp[cur][j] = std::max(dp[cur][j], dp[pre][j] + a[i].f);
		}
		ans = std::max(ans, dp[cur][0]);
	}

	std::cout << ans << "\n";
}