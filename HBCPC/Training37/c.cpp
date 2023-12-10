#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10, M = N * 2;

int n, a[N];

int h[N], ne[M], e[M], idx;

bool st[N];

int ans;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void init() {
	for (int i = 1; i <= n; i ++) {
		for (int j = i + i; j <= n; j += i) {
			a[j] += i;
		}
	}

	for (int i = 2; i <= n; i ++) {
		if (i > a[i])
			add(i, a[i]), add(a[i], i);
	}
}

int dfs(int u, int fa) {
	int d1 = 0, d2 = 0;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		// std::cout << v << "\n";

		if (v == fa) continue;

		st[v] = true;

		int d = dfs(v, u) + 1;

		if (d >= d1) d2 = d1, d1 = d;
		else if (d > d2) d2 = d;
	}

	ans = std::max(ans, d1 + d2);

	return d1;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n;	

	init();

	for (int i = 2; i <= n; i ++) {
		if (!st[i]) {
			dfs(i, -1), st[i] = true;
			// std::cout << ans << "\n";
		}
	}

	std::cout << ans;
}