#include <bits/stdc++.h>
#define f first
#define s second
using namespace std;
typedef pair<int, int> PII;
const int mod = 1e9 + 7, N = 1e3 + 10;

int dp[N][N];

int main() {
	int n, m; cin >> n >> m;
	vector<PII> p1(m);
	for (auto &x: p1) cin >> x.f >> x.s;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n;j ++) {
			dp[i][j] = (max(dp[i-1][j], dp[i][j - 1]) % mod + 1) % mod;
		}
	}
	cout << dp[n][n];
}