#include <iostream>
typedef int i8;
#define int long long
using namespace std;

const int N = 1e3 + 10;

int dp[N], v[N], w[N];

i8 main() {
	int n, m;
	cin >> m >> n;
	for(int i = 1; i <= n; i ++) {
		cin >> v[i] >> w[i];
	}
	for(int i = 1; i <= n; i ++) {
		for(int j = m; j >= v[i]; j --) {
			dp[j] = max(dp[j], dp[j - v[i]] + w[i]);
		}
	}
	cout << dp[m];
}