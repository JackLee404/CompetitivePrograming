/* CodeForces-1061C */
#include <iostream>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 1e6 + 10, mod = 1e9 + 7;

// 计数类背包
// dp[i][j] 表示从前i个数 抽取大小为j的数的个数
// | dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1] if (j | a[i])整除
// | dp[i][j] = dp[i - 1][j]
// dp[1][0] = 1

// 滚动数组
// dp[j] = dp[j] + dp[j - 1];

int a[N];
long long dp[N];

long long add(long long a, long long b) {
	return (a % mod + b % mod) % mod;
}

int main() {
	int n; cin >> n;

	dp[0] = 1;

	for(int i = 1; i <= n; i ++) {
		cin >> a[i];

		vector<int> curr;
		for (int j = 1; j <= a[i] / j; j ++) {
			if (a[i] % j == 0) {
				curr.push_back(j);
				if (a[i] / j != j)
					curr.push_back(a[i] / j);
			}	
		}
		sort(curr.begin(), curr.end(), greater<int>());
		for (auto &x: curr) {
			dp[x] = add(dp[x], dp[x - 1]);
		}
	}
	long long ans = 0;
	for (int i = 1; i <= n; i ++) ans = add(ans, dp[i]);
	cout << ans;
}