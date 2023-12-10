#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 3e5 + 10, M = 2 * N, mod = 1e9 + 7;

int n, r, a[N], ans = 0;

int h[N], ne[M], e[M], sz[N], idx;

int tr[N];

bool st[N], st2[N];

std::vector<int> g[N];

void dfs(int u, int cnt);

void plus(int x, int c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int query(int x) {
	int res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

void add(int a, int b) {
	// ne[idx] = h[a], h[a] = idx, e[idx ++] = b, sz[a] ++;
	g[a].push_back(b);
}

void dfs(int u, int cnt) {
	a[cnt] = u;

	for (int i = h[u]; ~i; i = ne[i]) {
		int j = e[i];
		if (st[j]) continue;
		st[j] = true;
		dfs(j, cnt + 1);
		st[j] = false;
	}
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> r;

	for (int i = 1; i <= n - 1; i ++) {
		int x, y;

		std::cin >> x >> y;

		add(x, y);
		add(y, x);
	}

	plus(r, 1);
	dfs(r, 1);
}