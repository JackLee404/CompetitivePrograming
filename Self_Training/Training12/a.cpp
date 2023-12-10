#include <iostream>

using i64 = long long;

const int N = (1 << 10) + 10;

int n, k;
/*
	f[i][j][k] 表示前i行，第i行的状态为j，皇后数量为k的 方案数

	则 f[i][j][k] = \sum f[i - 1][x][k - num(j)]

	其中x 为所有可能的状态

	可以先枚举第一行的状态，即为所有行的状态， 然后依次比较？
*/

int st[N], count[N], cnt;

i64 f[10][N][1000];

void dfs(int x, int num, int cur) {
	if(cur >= n) {
		st[++ cnt] = x;
		count[cnt] = num;
		return;
	}

	// 放皇后
	dfs(x + (1 << cur), num + 1, cur + 2);

	// 不放皇后
	dfs(x, num, cur + 1);
}

bool compatibal(int j, int x) {
	if(st[j] & st[x]) return false;
	if((st[j] << 1) & st[x]) return false;
	if((st[j] >> 1) & st[x]) return false;
	return true;
}

int main() {
	std::cin >> n >> k;

	dfs(0, 0, 0);

	for(int i = 1; i <= cnt; i ++) f[1][st[i]][count[i]] = 1;
	
	i64 ans = 0;

	for(int i = 2; i <= n; i ++) {
		for(int j = 1; j <= cnt; j ++) {
			for(int x = 1; x <= cnt; x ++) {
				if(!compatibal(j, x)) continue;
				
				for(int l = count[j]; l <= k; l ++) {	
					// if(l - count[x] < 0) continue;

					f[i][st[j]][l] += f[i - 1][st[x]][l - count[j]];
				}	
			}
		}
	}

	for(int i = 1; i <= cnt; i ++) ans += f[n][st[i]][k];

	std::cout << ans;
}