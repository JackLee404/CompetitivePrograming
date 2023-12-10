#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

const int N = 1e4 + 10;

int dp[N];

/*
	考虑01背包求方案， 并且保证字典序最小

	dp[i][j] 表示考虑i~n个物品，当背包容量为j时的方案数
*/

int main() {
	int n;

	std::cin >> n;

	for(int i = 0; i * i <= n; i ++) {
		for(int j = i; (i64)j * j + i * i <= n; j ++) {
			for(int l = j; (i64)l * l + j * j + i * i <= n; l ++) {
				for(int m = l; (i64)l * l + j * j + i * i + m * m <= n; m ++) {
					if((i64)l * l + j * j + i * i + m * m == n) {
						return std::cout << i << " " << j << " " << l << " " << m, 0;
					}
				}
			}
		}
	}
}