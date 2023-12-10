#include <bits/stdc++.h>

using i64 = long long;

const int N = 210, M = 30010;

int n, m;

bool d[N][N], g[N][N], st[N];

int match[N];

bool find(int x) {
	for (int i = 1; i <= n; i ++) {
		if (d[x][i] && !st[i]) {
			st[i] = true;
			int t = match[i];

			if (t == 0 || find(t)) {
				match[i] = x;
				return true;
			}	
		}	
	}

	return false;
}

int main() {
	std::cin >> n >> m;
	
	while (m --) {
		int a, b;
		
		std::cin >> a >> b;

		d[a][b] = true;		
	}	

	// 传递闭包

	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				d[i][j] |= d[i][k] & d[k][j];

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		memset(st, false, sizeof st);

		if (find(i)) res ++;	
	}

	std::cout << n - res;
}