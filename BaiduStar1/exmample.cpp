#include <iostream>

using namespace std;

const int N = 1e3 + 10, M = 2e4 + 10;

// 邻接表： vector, 链式前向星
vector<int> g[N];

bool a[N][N];

int n, m;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int u, v;

		cin >> u >> v;

		// 无向图 邻接矩阵
 		a[u][v] = a[v][u] = true;
		
 		// 无向图 邻接表
 		g[u].push_back(v), g[v].push_back(u);
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			cout << a[i][j] << " \n"[j == n];
		}
	}

	for (int i = 1; i <= n; i ++) {
		sort(g[i].begin(), g[i].end());

		for (int j = 0; j < g[i].size(); j ++) {
			cout << g[i][j] << " \n"[j == g[i].size() - 1];
		}
	}
}