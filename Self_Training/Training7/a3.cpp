#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

int dp[100][100][100];

int dx[]{-1,-1,0,0}, dy[]{-1,0,0,-1};

void solve() {
	int n, m;
	std::cin >> n >> m;
	
	memset(dp, 0, sizeof dp);

	std::vector<std::vector<int>> a(n + 1, std::vector<int>(m + 1));

	int _x, _y, _val;

    rep(i, 1, n)
        rep(j, 1, m)
            std::cin >> a[i][j];

	auto check = [&n, &m](int x1, int y1)->bool{
		return x1 >= 1 && x1 <= n && y1 >= 1 && y1 <= m;
	};

	dp[1][1][1] = a[1][1];

	rep(k, 2, 2 * n) {
		rep(x1, 1, n) {
			rep(x2, 1, n) {
				int y1 = k - x1, y2 = k - x2;
				if(x1 == x2) {
					dp[k][x1][x2] += a[x1][k - x1];
				} else {
					dp[k][x1][x2] += a[x1][k - x1] + a[x2][k - x2];
				}
				int mx = -1;
				if(check(x1, y1) && check(x2, y2)) {
					rep(i, 0, 3) {
						mx = std::max(mx, dp[k - 1][x1 + dx[i]][x2 + dy[i]]);
					}
					dp[k][x1][x2] += mx; 
				}
			}
		}
	}

	std::cout << dp[n + m][n][n] << "\n";
}

int main() {
	int _;
	_ = 1;
	while(_ --) {
		solve();
	}
}