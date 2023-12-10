#include <iostream>

typedef long long i64;

const int N = 1e3 + 10, M = 31;

int dp[N][M][M][M];

/*
	dp[i][a][b][c][j]
		 表示现在第i个踏板放在某个面上，其他三个面下一个踏板距离这个的距离为a, b, c, 当前这个踏板是否能从地面到达

	所以
	dp[i + 1][a + 1][b + 1][c + 1][j] += dp[i][a][b][c][j];
	dp[i + 1][1~h][b + 1][c + 1][j] += dp[i][a][b][c][j]; 
	dp[]
*/

int main() {

}