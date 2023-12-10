/*CodeForces-455A*/
#include <iostream>


using namespace std;

const int N = 1e5;

long long a[N], dp[N + 10];

/*
	dp[i] 表示考虑前i个数的最大收益
	dp[i] 可以从 dp[i - 2]转移过来
	dp[i] = max(dp[i - 2] + a[i] * k, dp[i - 2] + a[i - 1] * k)
*/

int main() {
	int n; cin >>n;
	for (int i = 1; i <= n; i ++) {
		int t; cin >> t; a[t] ++;
	}
	dp[1] = 1 * a[1];
	dp[2] = max(dp[1] , 2 * a[2]);
	for (int i = 3; i <= N; i ++) {
		dp[i] = max(dp[i - 1], dp[i - 2] + i * a[i]);	
	}
	cout << dp[N];
}