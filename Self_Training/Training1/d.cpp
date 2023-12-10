#include <iostream>
#include <map>
using namespace std;

const int N = 1e3 + 10;

int n, k, a[N];
map<int, pair<int, int>> b;

/*
	dp[i][j] 表示考虑前i个物品，当背包容量为j时的最大价值
	dp[i][j] 表示考虑前i个物品，当物品体积为j时的最小容量
	
	dp[i][j] = min(dp[i - 1][j], dp[i][j - v[i]] + w[i])

	可能为完全背包问题？
	dp[i][j] = min(dp[i - 1][j], dp[i][j - w[i]] + v[i]);

	dp[i][j - w[i]] = min (dp[i - 1][j - w[i]], dp[i][j - v[i]] + w[i], dp[i][j - 2w[i]] + 2v[i])

*/

int gcd(int a, int b) {
	return !b?a:gcd(b, a % b);
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= k; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= k; i ++) {

	}
}