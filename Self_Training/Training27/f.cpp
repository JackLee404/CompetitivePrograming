#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;

const int N = 110;

int n, m;

PII match[N][N];

bool g[N][N], st[N][N];

int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};

bool find(int x, int y) {
	for (int i = 0; i <= 3; i ++) {
		int a = x + dx[i], b = y + dy[i];
		if (a < 1 || a > n || b < 1 || b > n) continue;
		if (st[a][b] || g[a][b]) continue;

		PII t = match[a][b];
		st[a][b] = true;

		if (t.first == 0 || find(t.first, t.second)) {
			match[a][b] = {x, y};
			return true;	
		}
	}

	return false;
}

int main() {
	std::cin >> n >> m;

	while (m --) {
		int x, y;

		std::cin >> x >> y;

		g[x][y] = true;
	}

	int res = 0;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			if ((i + j) % 2 && !g[i][j]) {
				memset(st, 0, sizeof st);

				if (find(i, j)) res ++;
			}

	std::cout << res;
}