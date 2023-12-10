#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e5 + 10;

int h[N], e[M], ne[M], idx;

int n, m, ans, parent;

bool st[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void dfs(int u, int step) {
	if (step == 4) {
		ans ++;
		return;
	}

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (!st[v]) {
			st[v] = true;
			dfs(v, step + 1);
			st[v] = false;
		} else if(step == 3 && v == parent) {
			ans ++;
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		add(u, v), add(v, u);
	}

	for (int i = 1; i <= n; i ++) {
		st[i] = true;
		dfs(parent = i, 1);
		st[i] = false;
	}

	cout << ans;
}