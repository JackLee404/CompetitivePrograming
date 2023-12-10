#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

char a[1010], b[1010];

int dp[1010][1010];

int main() {
	int n, m; cin >> n >> m;
	cin >> (a+1) >> (b+1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= m; j ++) {
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if(a[i] == b[j]) dp[i][j] = dp[i - 1][j - 1] + 1;
		}
	}
	cout << dp[n][m];
}