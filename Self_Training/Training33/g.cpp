#include <bits/stdc++.h>

using i64 = long long;

typedef std::pair<int, int> PII;

const int N = 110;

int n, m;

int g[N][N], st[N][N];

PII match[N];

bool find(int x, int y) {
	static int dx[] = {0, -1, 1, 0}, dy[] = {1, 0, 0, -1};

	for (int i = 0; i <= 3; i ++) {
		int a = x + dx[i], b = y + dy[i];

		if (a < 1 || a > n || b < 1 || b > n) continue;

		if (st[a][b] || g[a][b]) continue;

		st[a][b] = true;

		PII t = match[a][b];

		if (t.x == -1 || fin(t.x, t.y)) {
			match[a][b] = {x, y};
			return true;
		}
	}

	return false;
}

int main() {
	memset(t, -1, sizeof t);

	std::cin >> n >> m;

	while (m --) {
		int x, y;

		std::cin >> x >> y;

		g[x][y] = true;
	}

	int res = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if ((i + j) % 2) {
				memset(st, 0, sizeof st);

				if (find(i, j)) res ++;	
			}
		}
	}
	
	std::cout << res;

	return 0;
}