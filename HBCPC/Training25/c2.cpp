#include <iostream>
#include <cstring>
using namespace std;

const int M = 525600, N = 3e4 + 10;

// dp[i][j] 为考虑前i个打卡卷，所需时间为j时的最大奖励数量 dp 物品和容量

// dp[i][j] dp 物品和价值
// dp[i][j] 表示考虑前i个物品，总价值为j时的最小时间
// dp[i][j] = min(dp[i-1][j], d[i][j-w[j]] + w[j])
// 一维数组
// dp[j] = min(dp[j], dp[j-w[j]] + w[j]);
// 复杂度O(3e7);
int v[N], w[N], dp[N];

int main() {
	int n, m, ans, tot = 0; cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> v[i];
	for (int j = 1; j <= n; j ++) cin >> w[j], tot += w[j];
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = tot; j >= w[i]; j --) {
			dp[j] = min(dp[j], dp[j-w[i]] + v[i]);
		}
	}
	int k = 1;
	while (dp[tot] > m) tot --;
	cout << tot;
}