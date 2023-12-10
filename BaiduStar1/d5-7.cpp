#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

vector<int> g[N];

int n, m, sx, sy;

int sum[N], cnt = 0;

bool st[N];

void dfs(int u) {
	if (u == sy) {
		cnt ++;
		for (int i = 1; i <= n; i ++) {
			if (st[i]) {
				sum[i] ++;
			}
		}
	} else {
		for (auto &x: g[u]) {
			if (st[x]) continue;

			st[x] = true;
			
			dfs(x);
			
			st[x] = false;
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		g[u].push_back(v), g[v].push_back(u);
	}

	int ans = 0;

	// 读入 x, y
	cin >> sx >> sy;

	dfs(sx);

	if (cnt) {
		for (int i = 1; i <= n; i ++) {
			if (sum[i] == cnt) {
				ans ++;
			}
		}

		cout << ans - 1;
	} else cout << "-1";

}