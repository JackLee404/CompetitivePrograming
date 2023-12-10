#include <iostream>
#include <vector>
#include <cstring>
using i64 = long long;

const int MAXN = 2300, inf = 0x3f3f3f3f;

/*
	dp[i][j] 表示一个序列以第i个数结尾, 且长度为j，另一个序列结尾的最小可能值(长度为 i - j)

	若a_i < a_(i+1) 更新 dp[i + 1][j + 1]
	若dp[i][j] < a_(i + 1) 更新 dp[i + 1][i - j + 1]	
*/

int dp[MAXN][MAXN];


void solve() {
	int m;
	std::cin >> m;
	std::vector<int> v(m + 1);

	memset(dp, 0x3f, sizeof dp);

	for(int i = 1; i <= m; i ++) std::cin >> v[i];

	dp[1][1] = -inf;

	for(int i = 1; i < m; i ++) {
		for(int j = 1; j <= i && j <= m / 2; j ++) {
			// 能衔接上序列， 更新dpi+1 j + 1
			if(v[i] < v[i + 1]) {
				dp[i + 1][j + 1] = std::min(dp[i + 1][j + 1], dp[i][j]);
			}

			// 能衔接上另一个序列 更新dpi+1, i - j + 1
			if(dp[i][j] < v[i + 1]) {
				dp[i + 1][i - j + 1] = std::min(dp[i + 1][i - j + 1], v[i]);
			}
		}
	}

	std::cout << (dp[m][m / 2] != 0x3f3f3f3f?"Yes!":"No!") << "\n";
}

int main() {
	int n;
	std::cin >> n;

	while(n --) {
		solve();
	}
}