#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int t, dp[100]; cin >> t;
	memset(dp, 0, sizeof dp);
	dp[1] = 1, dp[2] = 2;
	for (int i = 1; i <= 80; i ++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	while (t--) {
		int m; cin >> m;
		cout << m << "\n";
	}
}