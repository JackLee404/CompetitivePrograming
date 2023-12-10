#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e5 + 10, M = 2e5 + 10;

int n, m;

int h[N], e[M], ne[M], idx;

int h2[N], e2[M], ne2[M], idx2;

bool st[N];

double w[M], val[N], ans;

double b[N];

std::map<int, double> mp;

/*
	val[i] 表示从i到n的最大概率
*/

void add(int a, int b, int c) {
	ne[idx] = h[a], h[a] = idx, w[idx] = c, e[idx ++] = b;
}

/*
	dfs 表示从u到终点的概率
*/

double dfs(int u) {
	if (mp.count(u)) return mp[u];

	double sum = 0;

	int cnt = 0;

	std::cout << u << "\n";
	
	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];
 	
 		double t = dfs(v);

		b[++ cnt] = t;


		sum += t;
	}

	// std::cout << "sum:" << sum << "\n";

	if (sum == 0) return mp[u] = 1;

	double res = 0;

	for (int i = h[u], j = 1; ~i; i = ne[i], j ++) {
		int v = e[i];

		double t = 0.01 * w[i] * b[j] + (1 - 0.01 * w[i]) * (sum - b[j]) * ;

		res = std::max(res, t);
	}

	return mp[u] = res;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		val[i] = 1;
	}

	while (m --) {
		int x, y, c;

		std::cin >> x >> y >> c;

		add(x, y, c);
	}

	mp[n] = 1;

	// printf("%.6lf", dfs(1));

	dfs(1);
	
	for (int i = 1; i <= n; i ++) {
		std::cout << mp[i] << "\n";
	}
}
