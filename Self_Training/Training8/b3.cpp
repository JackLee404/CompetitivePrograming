#include <iostream>
#include <algorithm>
#define INF 0x3f3f3f3f
using i64 = long long;

const int N = 100;

int dx[] = {-2, -1, 1, -2}, dy[] = {1, 2, 2, -1};

i64 dp[N][N];

int n, m;

bool check(int x, int y) {
	return x >= 0 && x <= n && y >= 0 && y <= m;
}

int main() {
	int x1, y1;	

	std::cin >> n >> m >> x1 >> y1;

	dp[x1][y1] = INF;

	for(int i = 0; i <= 3; i ++) {
		int x = x1 + dx[i], y = y1 + dy[i];
		// std::cout << x << " " << y << "\n";
		if(check(x, y)) {
			dp[x][y] = INF;
		}
		x = x1 + dy[i], y = y1 + dx[i];
		if(check(x, y)) {
			dp[x][y] = INF;
		}
		// std::cout << x <<  " " << y << "\n";
	}

	dp[0][0] = 1;

	for(int i = 0; i <= 20; i ++) {
		for(int j = 0; j <= 20; j ++) {
			if(dp[i][j] == INF) continue;
 			if(i > 0 && dp[i - 1][j] != INF) dp[i][j] += dp[i - 1][j];
			if(j > 0 && dp[i][j - 1] != INF) dp[i][j] += dp[i][j - 1]; 
		}
	}

	std::cout << dp[n][m];
}