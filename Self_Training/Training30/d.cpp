#include <bits/stdc++.h>

using i64 = long long;

const int N = 5e5 + 10, M = 2e5 + 10;

int n, m;

int h[N], e[M], ne[M], idx;

double w[M];

std::unordered_map<int, double> hash;

struct node {
	int id;
	double val;

	bool operator>(const node t) const {
		return val > t.val;
	}
};

void add(int a, int b, double c) {
	ne[idx] = h[a], h[a] = idx, e[idx] = b, w[idx ++] = c;
}

double dfs(int u) {
	if (u == n) return 1;

	if (hash.count(u)) return hash[u];

	std::vector<node> f;

	for (int i = h[u]; ~i; i = ne[i]) {
		int v = e[i];		

		f.push_back({i, dfs(v)});
	}

	/*
		f[cnt] * w[h[u] + cnt - 1]] * \prod (1 -  w[(h[u], h[u] + cnt - 2)])
	*/

	std::sort(f.begin(), f.end(), std::greater<node>());

	// std::cout << u <<  "<-point\n";

	// for (int i = 0; i < f.size(); i ++) {
	// 	std::cout << f[i].val << " \n"[i == (int) f.size() - 1];
 	// }

	double ans = 0, t = 1;

	for (int i = 0; i < f.size(); i ++) {
		double val = f[i].val;
		int id = f[i].id;

		ans += val * w[id] * t;

		// std::cout << val << " " << w[h[u] + id] << "\n";

		t *= (1 - w[id]);
	}

	// std::cout << ans << "<-res\n";

	return hash[u] = ans;
}

int main() {
	memset(h, -1, sizeof h);

	std::cin >> n >> m;

	while (m --) {
		int x, y;

		double c;

		std::cin >> x >> y >> c;

		c *= 0.01;

		add(x, y, c);
	}

	printf("%.6lf", dfs(1));
}
