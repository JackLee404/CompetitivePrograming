#include <iostream>
#include <cstring>
using namespace std;

// dp[i][j]表示当前点的最大值
// cnt[i][j]表示当前点的最优方案的数量

int a[105][105], dp[105][105], cnt[105][105];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			cin >> a[i][j];	
		}
	}

	memset(dp, -0x3f, sizeof dp);
	
	cnt[1][1] = 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			if(i - 1 == 0 && j - 1 == 0) {
				dp[i][j] = a[i][j];
				continue;
			}
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + a[i][j];	
			if(dp[i - 1][j] > dp[i][j - 1]) {
				cnt[i][j] += cnt[i - 1][j];
			} else if(dp[i - 1][j] < dp[i][j - 1]) {
				cnt[i][j] += cnt[i][j - 1];
			} else {
				cnt[i][j] += cnt[i - 1][j];
				cnt[i][j] += cnt[i][j - 1];
			}
		}
	}
	cout << dp[n][m] << " " << cnt[n][m];
}