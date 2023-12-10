#include <iostream>
#include <cstring>
using namespace std;

const int N = 2e3 + 10, maxn = 0x3f3f3f3f;

bool st[N];

int g[N][N];

int n, m;

void dfs(int u) {
	for (int v = 1; v <= n; v ++) {
		if (st[v] || g[u][v] == maxn) continue;

		st[v] = true;

		cout << v << "\n";

		dfs(v);
	}
}

int main() {
	memset(g, 0x3f, sizeof g);

	cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int x, y, z;

		cin >> x >> y >> z, g[x][y] = z, g[y][x] = z;
	}

	for (int i = 1; i <= n; i ++) {
		if (!st[i]) dfs(i);
	}
}