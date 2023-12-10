#include <bits/stdc++.h>

using i64 = long long;

const int N = 600, M = 1e4 + 10;

int f[N][N], q[M];

int main() {
	int n, m;
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		int v, w, s;
		std::cin >> v >> w >> s;

		for(int r = 0; r < v; r ++) {
			int hh = 0, tt = -1;
			for(int k = r; k <= m; k += v) {
				if(hh <= tt && k - q[hh] > s * v) hh ++;	
				while(hh <= tt && f[i - 1][q[tt]] + (k - q[tt]) / v * w <= f[i - 1][k]) tt --;
				q[++ tt] = k;
				f[i][k] = f[i - 1][q[hh]] + (k - q[hh]) / v * w;
			}
		}
	}

	std::cout << f[n][m];
}