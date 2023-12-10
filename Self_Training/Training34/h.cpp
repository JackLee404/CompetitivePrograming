#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

const int N = 40, M = 4000;

typedef std::pair<int, int> PII;

int n, m, cnt;

char a[N][N];

bool st[N];

int h[N], e[M], ne[M], idx;

int id[N][N], d[N][N], match[M];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void init() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			if (id[i][j]) {
				if (id[i][j + 1]) {
					d[id[i][j]][id[i][j + 1]] = 1;
				}
				if (id[i + 1][j]) {
					d[id[i][j]][id[i + 1][j]] = 1;
				}		
			}
		}	
	}

	for (int k = 1; k <= cnt; k ++) {
		for (int i = 1; i <= cnt; i ++) {
			for (int j = 1; j <= cnt; j ++) {
				d[i][j] |= d[i][k] & d[k][j];
			}
		}	
	}
}

int find(int u) {
	for (int i = 1; i <= cnt; i ++) {
		if (st[i] || !d[u][i]) continue;

		st[i] = true;

		if (!match[i] || find(match[i])) {
			match[i] = u;
			return true;		
		}
  	}
  	return false;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	int sum = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			std::cin >> a[i][j];
			if (a[i][j] == '1') id[i][j] = ++ cnt;
			sum += (a[i][j] == '1');
		}
	}		

	init();

	int res = 0;

	for (int i = 1; i <= cnt; i ++) {
		memset(st, 0, sizeof st);

		if (find(i)) res ++;
	}

	std::cout << sum - res << "\n";
}