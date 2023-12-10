#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10, M = N * 2;

int h[N], ne[M], e[M], idx;

int color[N];

bool st[N], st2[M];

int n;

std::map<std::pair<int, int>, bool> mp;

void add(int a, int b) {
	ne[idx] = h[a], h[a] = idx, e[idx ++] = b;
}

bool dfs(int u, int c) {
	color[u] = c;

	for (int i = h[u]; ~i; i = ne[i]) {
		if (st2[i]) continue;

		int v = e[i];

		if (color[v] == -1) {
			if (!dfs(v, !c)) return false;
		} else if (color[v] == c) return false;
	}

	return true;
}

bool check() {
	memset(color, -1, sizeof color);

	for (int i = 1; i <= n; i ++) {
		if (color[i] == -1) {
			if (!dfs(i, 0)) {
				return false;
			}
		}
 	}
}

int main() {
	memset(h, -1, sizeof h);
	
	std::cin >> n;

	for (int i = 1; i < n; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b), add(b, a);

		if (a > b) std::swap(a, b);

		mp[{a, b}] = true;
	}

	i64 ans = 0;

	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
			if (mp[{i, j}]) continue;
			
			add(i, j), add(j, i);

			if (check()) {
				ans ++;
			}

			st2[idx - 1] = st2[idx - 2] = true;
		}
	}

	std::cout << ans;
}