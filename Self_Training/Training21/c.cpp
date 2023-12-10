#include <iostream>

using i64 = long long;

i64 f[2020][2020];

/*
	f[i][j] 表示第一行i个数，第二行j个数的状态
	f[i][j] += f[i - 1][j]; 放到第一行
	f[i][j] += f[i][j - 1]; 放到第二行
*/
int main() {
	f[0][0] = 1;

	for (int i = 1; i <= 1010; i ++) {
		for (int j = 0; j <= i; j ++) {
			f[i][j] += f[i][j - 1]; f[i][j] %= 2020;
			
			if (i - 1 >= j)
				f[i][j] += f[i - 1][j]; f[i][j] %= 2020;
		}
	}

	std::cout << f[1010][1010] % 2020 << "\n";
}