#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e4 + 10, M = 2e5 + 10;

int n, m;

int h[N], e[M], ne[M], w[M], idx;

int color[N]; // 0没有染色， 1，2两个不同的颜色

/*
	check(mid)

	对于积怨值大于mid的两个罪犯分别关到不同的监狱内

	等价于：除去积怨值小于等于mid的边，子图能否构成二分图

	显然能构成二分图的子图也能构成二分图， 所以满足二段性

	即[不满足，满足]两段，那么结果就是第一个满足的mid
*/

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

bool dfs(int u, int c, int mid) {
	color[u] = c;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];

		if (w[i] <= mid) continue;

		if (color[v]) {
			if (color[v] == c) return false;
		} else if (!dfs(v, 3 - c, mid)) return false;
	}

	return true;
}

bool check(int mid) {
	memset(color, 0, sizeof color);

	for (int i = 1; i <= n; i ++)
		if (color[i] == 0)
			if (!dfs(i, 1, mid)) return false;

	return true;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	while (m --) {
		int a, b, c;

		std::cin >> a >> b >> c;

		add(a, b, c), add(b, a, c);
	}

	int l = 0, r = 1e9;

	while (l < r) {
		int mid = l + r >> 1;

		if (check(mid)) r = mid;
		else l = mid + 1;
	}

	std::cout << l;
}