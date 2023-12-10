#include <bits/stdc++.h>

using i64 = long long;

const int N = 210;

std::unordered_map<int, int> idx;

int n, k, m, S, E;

int g[N][N], res[N][N];

inline int get(int x) {
	if (idx.count(x)) {
		return idx[x];
	} return idx[x] = ++ n;
}

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

	while (k) {
		if (k & 1) mul(res, res, g);
		mul(g, g, g);
		k >>= 1;
	}
}

int main() {
	memset(g, 0x3f, sizeof g);

	std::cin >> k >> m >> S >> E;

	get(S);
	get(E);

	while (m --) {
		int a, b, c;

		std::cin >> a >> b >> c;

		int k1 = get(b), k2 = get(c);

		g[k1][k2] = g[k2][k1] = std::min(g[k1][k2], a);
	}

	// std::cout << n << "\n";

	qmi();

	std::cout << res[get(S)][get(E)];	
}