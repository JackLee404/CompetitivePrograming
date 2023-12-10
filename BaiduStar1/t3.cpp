#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

int h[N], e[M], ne[M], idx;

int n, m;

bool st[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

// dfs表示 返回以u为根的子树的最大值
int dfs(int u) {
	st[u] = true;

	int mx = u;

	for (int i = h[u]; i != -1; i = ne[i]) {
		int v = e[i];

		mx = max(mx, dfs(v));
	}

	return mx;
}

int main() {
	memset(h, -1, sizeof h);

	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		add(u, v);
	}

	// " \n"[i == n] i!=n -> " ", i == n -> "\n"

	for (int i = 1; i <= n; i ++) {
		memset(st, false, sizeof st);
		
		cout << dfs(i) << " \n"[i == n];
	}
}