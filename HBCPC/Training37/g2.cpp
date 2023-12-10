#include <bits/stdc++.h>

using i64 = long long;

const int N = 1510, M = N;

int h[N], e[M], ne[M], idx;
int f[N][2];

bool st[N];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

void dfs(int u) {
	f[u][0] = 0;
	f[u][1] = 1;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		dfs(v);

		f[u][0] += f[v][1];	
		f[u][1] += std::min(f[v][0], f[v][1]);
	}
}

int main() {

	int n;

	while (std::cin >> n) {
		memset(h, -1, sizeof h);

		idx = 0;

		for (int i = 1; i <= n; i ++) {
			int id, cnt;
			
			scanf("%d:(%d)", &id, &cnt);

			while (cnt --) {
				int ver;

				scanf("%d", &ver);

				add(id, ver);

				st[ver] = true;
			}	
		}

		int root = 0;

		while (st[root]) root ++;

		dfs(root);

		printf("%d\n", std::min(f[root][0], f[root][1]));
	}
}