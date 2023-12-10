#include <iostream>
#include <cstring>
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;

const long long mod = 1e9 + 7;

//fij 第i天时, 购买第j个套餐的最多种数
//f[i][3] = f[i-1][1] + f[i - 1][2] + f[i-1][3] - f[i - 2][3]
//f[1][j] = 1
//f[0][j] = 1
//f[2][3] = f[1][1] + f[1][2] + f[1][3] - f[0][3] = 3
int main() {
	long long t, n, f[100005][5];
	cin >> t;
	memset(f, 0, sizeof f);
	for (int i = 1; i <= 3; i ++) f[1][i] = 1;
	for (int i = 2; i <= 100000; i ++) {
		f[i][3] = f[i - 1][1] + f[i - 1][2] + f[i - 1][3] - f[i - 2][3];
		f[i][2] = f[i - 1][1] + f[i - 1][3] + f[i - 1][2] - f[i - 2][2];
		f[i][1] = f[i - 1][2] + f[i - 1][3] + f[i - 1][1] - f[i - 2][1];
		rep (j, 1, 3) {
			f[i][j] %= mod;
		}
	}
	while (t --) {
		cin >> n; cout << (f[n][1] + (f[n][2] + f[n][3]) % mod) % mod << "\n";
	}
}