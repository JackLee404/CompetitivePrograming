#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

// dp[i] 表示以第i个数结尾的最大上升子序列
// 对于第i-1个数，若其小于dp[i] 显然dp[i - 1] + 1 时dp[i]集合的一部分
// 否则dp[i]等于

int main() {
	int n; cin >> n;
	vector<int> a(n + 1), dp(n + 1);
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++) {
		if (i == 1) dp[i] = 1;
		else {
			for (int j = 1; j <= i - 1; j ++) {
				if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
			}
		}
	}
	cout << *max_element(dp.begin() + 1, dp.end());
}