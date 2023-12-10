#include <iostream>
#include <algorithm>
using namespace std;

char a[35][65];

bool st[35][65];

int dx[] = {0, 1}, dy[] = {1, 0};

long long ans = -1;

//void dfs(int x, int y, long long sum) {
//	cout << x << " " << y << endl;
//	if (x == 30 && y == 60) {
//		ans = max(ans, sum);
//		return;
//	}
//	for (int i = 0; i <= 1; i ++) {
//		int tx = x + dx[i], ty = y + dy[i];
//		if (tx >= 1 && tx <= 30 && ty >= 1 && ty <= 60 && !st[tx][ty]) {
//			st[tx][ty] = true;
//			dfs(tx, ty, sum + (a[tx][ty] - '0'));
//		}
//	}
//}

long long dp[35][65];

int main() {
	for (int i = 1; i <= 30; i ++) {
		scanf("%s", a[i] + 1);
	}
//	st[1][1] = true;
//	dfs(1, 1, 0);
//	cout << ans << endl;
	for (int i = 1; i <= 30; i ++) {
		for (int j = 1; j <= 60; j ++) {
			if (i == 1 && j == 1) {
				dp[i][j] = a[i][j] - '0';
			} else {
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (a[i][j] - '0');
			}
		}
	}
	cout << dp[30][60] << endl;
	// ¼ì²é´íÎó 
	cout << dp[1][2] << endl;
	cout << dp[2][2] << endl;
	cout << dp[2][3] << endl;
}
