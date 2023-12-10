
#include <iostream>
#include <cstring>

const int N = 1e3 + 10, M = 2e4 + 10;

int q[M];
int f[M], g[M], v[N], w[N], s[N];
int n, m;

int main() {
	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		std::cin >> v[i] >> w[i] >> s[i];
	}

	for(int i = 1; i <= n; i ++) {	
		memcpy(g, f, sizeof f);
		for(int r = 0; r < v[i]; r ++) {
			int hh = 0, tt = -1;
			for(int j = r; j <= m; j += v[i]) {
				if(hh <= tt && j - q[hh] > s[i] * v[i]) hh ++;
				while(hh <= tt && g[q[tt]] + (j - q[tt]) / v[i] * w[i] <= g[j]) tt --;
				q[++ tt] = j;
				f[j] = g[q[hh]] + (j - q[hh]) / v[i] * w[i];
			}
		}
	}

	std::cout << f[m];
}