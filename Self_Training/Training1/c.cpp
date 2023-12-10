#include <iostream>
using namespace std;

const int N = 1e5 + 10;
const long long INF = 9e18 + 10;

long long dp[N][3];

int main() {
	ios::sync_with_stdio(0);
	long long n, p, q, r, a[N]; cin >> n >> p >> q >> r;
	for(int i = 1; i <= n; i ++) cin >> a[i];

	dp[0][0] = dp[0][1] = dp[0][2] = -INF;

	for(int i = 1; i <= n; i ++) {
		dp[i][0] = max(dp[i - 1][0], p * a[i]);
		dp[i][1] = max(dp[i - 1][1], dp[i][0] + q * a[i]);
		dp[i][2] = max(dp[i - 1][2], dp[i][1] + r * a[i]);
	}
	cout << dp[n][2];
}