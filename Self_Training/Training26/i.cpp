#include <bits/stdc++.h>

using i64 = long long;

const int N = 6e3 + 10;

struct Edge {
	int a, b, w;

	void input() {
		std::cin >> a >> b >> w;
	}

	void out() {
		std::cout << a << " " << b << " " << w << "\n";
	}

	bool operator<(const Edge &t) const {
		return w < t.w;
	}
}edge[N];


int n, m;

int p[N], sz[N];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

i64 kruskal() {
	std::sort(edge + 1, edge + n);	

	i64 res = 0;

	for (int i = 1; i <= n - 1; i ++) {
		int a = edge[i].a, b = edge[i].b, w = edge[i].w;

		// edge[i].out();
		
		int fa = find(a), fb = find(b);

		if (fa != fb) {
			res += (sz[fa] * sz[fb] - 1) * (w + 1);
			p[fa] = fb;
			sz[fb] += sz[fa];
		}
	}

	return res;
}

void solve() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {		
		p[i] = i, sz[i] = 1;
	}

	for (int i = 1; i <= n - 1; i ++) {
		edge[i].input();
	}

	std::cout << kruskal() << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}