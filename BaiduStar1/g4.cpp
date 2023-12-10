#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e3 + 10;

// 假设有 N 个点

vector<int> g[N];

bool st[N];

// n 代表点数， m代表边数
int n, m;

void dfs(int u) {
	st[u] = true;

	cout << u << "\n";

	for (auto &x: g[u]) {
		if (st[x]) continue;

		dfs(x);
	}
}

void bfs(int u) {
	queue<int> q1;

	// 先放入原点
	q1.push(u);

	st[u] = true;

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		cout << u << " ";

		for (auto &x: g[u]) {
			if (st[x]) continue;

			// 保证不会放入之前入过队的点
			st[x] = true;

			q1.push(x);
		}
	}
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		// 有向图
		g[u].push_back(v);

		// 无向图
		g[v].push_back(u);
	}

	bfs(1);
}