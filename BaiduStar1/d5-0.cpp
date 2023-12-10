#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e3 + 10, M = 4e3 + 10;

int n, m;

int h[N], e[M], ne[M], idx;

int st, ed, d[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void bfs() {
	memset(d, -1, sizeof d);

	queue<int> q1;

	q1.push(st);

	d[st] = 0;

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			if (d[v] == -1) {
				d[v] = d[u] + 1;
				q1.push(v);
			}
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

	// d[ed] = 2 经过一个点 答案为1 d[ed]

	cin >> st >> ed;

	bfs();

	int ans = -1;

	if (d[ed] > 2) ans = 2;
	else if (d[ed] != -1) ans = d[ed] - 1;

	cout << ans;
}