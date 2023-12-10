#include <iostream>
#include <algorithm>

using i64 = long long;

const int mod = 1e9 + 7, N = 200;

/* 
	f[i][j][k] 

	表示李白经过第i个地点， 该地点状态为k时，且酒的数量为j的方案数量
*/

int n, m;

int f[N][1010][2];

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);


	std::cin >> n >> m;

	f[0][2][0] = 1;

	// f[0][2][1] = 1;

	// f[0][0][1] = 1;

	for(int i = 1; i <= n + m; i ++) {
		for(int k = 0; k <= 1000; k ++) {	
			f[i][k][0] = f[i - 1][k + 1][0] + f[i - 1][k + 1][1];


			// if((k + 1) % 2 == 0) {
			// 	f[i][k][0] += + f[i - 1][k + 1][1];
			// }

			if(k % 2 == 0) {
				f[i][k][1] = f[i - 1][k / 2][1] + f[i - 1][k / 2][0];
			}
		}
	}

	std::cout << f[n + m][0][0] << "\n";

	// for(int i = 1; i <= n + m; i ++) {
	// 	for(int k = 0; k <= 0; k ++) {
	// 		std::cout << f[i][k][0] << " \n"[i == n + m];
	// 	}
	// }

}