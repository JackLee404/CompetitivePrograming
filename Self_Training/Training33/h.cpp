#include <bits/stdc++.h>

using i64 = long long;

const int N = 110;

int n, m, k;

bool g[N][N], st[N];

int match[N];

bool find(int x) {
	for (int i = 1; i < m; i ++) {
		if (!st[i] && g[x][i]) {
			st[i] = true;
			int t = match[i];

			if (!t || find(t)) {
				match[i] = x;
				return true;
			}
		}
	}
	return false;
}

int main() {
	while (std::cin >> n, n) {

		std::cin >> m >> k;
		
		memset(g, 0, sizeof g);
		memset(match, 0, sizeof match);

		while (k --) {
			int t, a, b;

			std::cin >> t >> a >> b;

			if (!a || !b) continue;

			g[a][b] = true;
		}	

		int res = 0;

		for (int i = 1; i < n; i ++) {
			memset(st, 0, sizeof st);

			if (find(i)) res ++;
		}

		std::cout << res << "\n";
	}
}