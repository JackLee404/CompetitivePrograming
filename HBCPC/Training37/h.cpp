#include <bits/stdc++.h>

using i64 = long long;

const int N = 1510;

int h[N], e[N], ne[N], w[N], idx;

int n;

bool st[N];

int f[N][3];

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;	
}

void dfs(int u) {
	f[u][2] = w[u];

	int sum = 0;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		dfs(v);
		
		f[u][0] += std::min(f[v][2], f[v][1]);	
		f[u][2] += std::min(f[v][0], std::min(f[v][1], f[v][2]));

		sum += std::min(f[v][1], f[v][2]);
	}

	f[u][1] = 1e9;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
		
		f[u][1] = std::min(f[u][1], sum - std::min(f[v][1], f[v][2]) + f[v][2]);
	}
}


int main() {
	std::cin >> n;

	memset(h, -1, sizeof h);

	for (int i = 1; i <= n; i ++) {
		int id, cost, cnt;
		
		std::cin >> id >> cost >> cnt;

		w[id] = cost;

		while (cnt --) {
			int ver;
			
			std::cin >> ver;

			add(id, ver);

			st[ver] = true;					
		}
	}

	int root = 1;

	while (st[root]) root ++;

	dfs(root);

	std::cout << std::min(f[root][1], f[root][2]);
}