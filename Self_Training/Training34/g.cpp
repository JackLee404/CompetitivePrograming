#include <bits/stdc++.h>

using i64 = long long;

const int N = 110, mod = 1e9 + 7;

int n, m;

char s[N][N];

int f[N][N][N];

/*
	f[i][l][r] 表示已经摆好i - 1 ~ n, 在区间[l, r] 内连续摆放一段积木的方案数
*/

int dfs(int dep, int l, int r) {
	if (dep == 0) return 1;
	if (f[dep][l][r] != -1) return f[dep][l][r];

	i64 ans = 1;

	for (int i = l; i <= r; i ++) {
		if (s[dep][i] == '.') {
			for (int j = i; j <= r; j ++) {
				// 若区间内有'X' break
				if (s[dep][j] == 'X') {
					break;
				}
				ans = (ans + dfs(dep - 1, i, j)) % mod;
			}	
		}	
	}
	f[dep][l][r] = ans;
	return f[dep][l][r];
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> s[i] + 1;	
	}

	memset(f, -1, sizeof f);

	dfs(n, 1, m);

	std::cout << f[n][1][m];
}