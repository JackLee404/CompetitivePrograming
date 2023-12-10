#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e3 + 10, M = 2 * N;

// int h[N], e[M], ne[M], w[M], idx;

int pre[N], a[N];

int n, c;

// void add(int a, int b) {
// 	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = std::abs(b - a - c);
// }


int g[N][N], res[N][N];

void mul(int c[][N], int a[][N], int b[][N]) {
	static int tmp[N][N];

	memset(tmp, 0x3f, sizeof tmp);

	for (int k = 1; k <= n; k ++)
		for (int i = 1; i <= n; i ++)
			for (int j = 1; j <= n; j ++)
				tmp[i][j] = std::min(tmp[i][j], a[i][k] + b[k][j]);

	memcpy(c, tmp, sizeof tmp);
}

void qmi() {
	memset(res, 0x3f, sizeof res);

	for (int i = 1; i <= n; i ++) res[i][i] = 0;

	int k = n;

	while (k) {
		if (k & 1) mul(res, res, g);
		mul(g, g, g);
		k >>= 1;
	}
}
void solve() {
	std::cin >> n >> c;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			int x = a[i], y = a[j];
			g[x][y] = std::abs(y - x - c);
			g[y][x] = std::abs(x - y - c);
		}
	}

	// std::cout << g[1][9] << "\n";

	qmi();

	std::cout << res[1][9] << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}