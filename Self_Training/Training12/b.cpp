#include <iostream>
#define F(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

const int N = 20, mod = 1e8, M = 1e6;

int a[N], st[M], cnt, n, m;

int f[20][M];

bool check(int x) {
	for(int j = 0; j < m - 1; j ++) {
		if((x >> j & 1) && (x >> j + 1 & 1)) {
			return false;
		}
	}
	return true;
}

int main() {
	std::cin >> n >> m;

	F(i, 1, n) {
		F(j, 1, m) {
			int x;
			std::cin >> x;

			a[i] += (x << (j - 1));	
		}
	}

	F(i, 0, (1<<m) - 1) {
		if(check(i)) {
			st[++ cnt] = i;
		}
	}

	// std::cout << cnt << "\n";

	f[0][1] = 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j <= cnt; j ++) {
			if(st[j] & (~a[i])) continue;

			for(int k = 1; k <= cnt; k ++) {
				if(st[j] & st[k]) continue;
				
				f[i][j] = ((i64)f[i][j] + f[i - 1][k]) % mod;
			}
		}
	}


	i64 ans = 0;

	for(int i = 1; i <= cnt; i ++) ans += f[n][i], ans %= mod;

	std::cout << ans;
}