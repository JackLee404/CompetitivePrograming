#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e4 + 10, M = 2e4 + 10;

int n;

int h[N], ne[M], e[M], w[M], idx;

int ans;

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

int dfs(int u, int fa) {
	int d1 = 0, d2 = 0;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (v == fa) continue;

		int d = dfs(v, u) + w[i];

		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
	}

	ans = std::max(ans, d1 + d2);

	return d1;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n;

	for (int i = 1; i < n; i ++) {
		int a, b, c;	

		std::cin >> a >> b >> c;

		add(a, b, c), add(b, a, c);
	}

	dfs(1, -1);

	std::cout << ans
}