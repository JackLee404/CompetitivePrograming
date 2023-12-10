#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10, M = 2e6 + 10, mod = 998244353;

int n, m;

int h[N], e[M], ne[M], idx;

bool st[N];

int cnt;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

i64 qmi(i64 a, i64 b) {
	i64 res = 1;
	while (b) {
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res % mod;
}

void dfs(int u) {
	if (st[u]) return;

	st[u] = true;

	cnt ++;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (st[v]) continue;

		dfs(v);
	}
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int x, y; 
		std::cin >> x >> y;
		add(x, y), add(y, x);
	}

	i64 ans = 1;

	for (int i = 1; i <= n; i ++) {
		if (!st[i]) {
			cnt = 0;
			dfs(i);
			ans = ans * (qmi(2, cnt) - 1) % mod;
		}	
	}

	std::cout << ans;
}
