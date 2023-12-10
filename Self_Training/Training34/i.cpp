#include <bits/stdc++.h>
#include <sstream>

using i64 = long long;

const int N = 1e5 + 10, M = 2e5 + 10;

int n, m;

int h[N], ne[M], e[M], idx;

int f[N], en[N];

bool st[N], st2[N];

std::unordered_map<i64, i64> hash;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

i64 get(i64 x, i64 y) {
	return x * (30000 + 1) + y;	
}

int dfs(int u) {
	st[u] = true;

	int res = 1;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (st2[v]) continue;
		
		if (st[v]) {
			res += f[v];
			continue;
		}

		st[v] = true;

		st2[v] = true;

		res += dfs(v);
	}

	return f[u] = res;
}

void bfs() {
	std::queue<int> q1;

	for (int i = 1; i <= n; i ++) {
		if (!en[i]) q1.push(i);
	}

	while (q1.size()) {
		int u = q1.front(); q1.pop();

		if (!st[u]) {
			memset(st2, false, sizeof st2);
			dfs(u);
		}

		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];

			en[v] --;

			if (!en[v]) {
				q1.push(v);
			}
		}
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= m; i ++) {
		int a, b;

		std::cin >> a >> b;

		if (hash[get(a, b)]) {
			continue;
		}

		hash[get(a, b)] = true;

		add(a, b);

		en[b] ++;
	}

	int ans = 0;

	bfs();


	for (int i = 1; i <= n; i ++) {
		std::cout << f[i] << "\n";
	}
}