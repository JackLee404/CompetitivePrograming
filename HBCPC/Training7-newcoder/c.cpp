#include <iostream>

using namespace std;

const int N = 1e5 + 10;

int a[N], dp[N], n, k, ans;

// void dfs(int i, int length) {
// 	if (i > n) {
// 		ans = max(ans, length);
// 		return;
// 	}
// 	dfs(i + k + 1, length + a[i]);
// 	dfs(i + 1, length);
// }

int main() {
	ans = -0x3f3f3f3f;
	cin >> n >> k;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	// 比赛时没做出来  下面代码为看题解后做的
	// dp[i] 表示考虑前i个数的最优解
	// dp[i] = max(dp[i - 1], dp[i - k + 1] + a[i])
	dp[1] = a[1];
	for (int i = 2; i <= n; i ++) {
		if (i >= k + 1) {
			dp[i] = max(dp[i - 1], dp[i - k - 1] + a[i]);
		} else {
			dp[i] = max(dp[i - 1], a[i]); 
		}
	}
	cout << dp[n] << endl;
}