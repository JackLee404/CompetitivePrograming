#include <iostream>
#include <algorithm>

using i64 = long long;

const int mod = 1e9 + 7, N = 200;

/* 
	f[i][j][k] 

	表示经过了i次店，j朵花, 当前酒量为k时的方案数

	f[i][j][k] =  f[i - 1][j][k + 1] + f[i][j - 1][k >> 1];
*/

int n, m;

int f[N][N][1010];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);


	std::cin >> n >> m;

	f[0][0][2] = 1;

	for(int i = 0; i <= n; i ++) {
		for(int j = 0; j <= m; j ++) {
			for(int k = 0; k <= 1000; k ++) {
				if(j)	
					f[i][j][k] += f[i][j - 1][k + 1];

				if(i && k % 2 == 0) {
					f[i][j][k] = ((i64)f[i][j][k] + f[i - 1][j][k >> 1]) % mod;
				}
			}
		}
	}

	std::cout << f[n][m - 1][1];
}