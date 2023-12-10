#include <bits/stdc++.h>
#define ff first
#define ss second
using i64 = long long;

const int N = 600, M = 1e4 + 10;

int n, m, k;

int p[N], sz[N];

struct Edge {
	int a, b;

	double w;

	bool operator<(const Edge &t) const {
		return  w < t.w;
	}	
}edge[M];

std::vector<std::pair<int, int>> v1;

double get_dist(int i, int j) {
	int dx = v1[i].ff - v1[j].ff;
	int dy = v1[i].ss - v1[j].ss;

	return sqrt(std::abs(dx * dx + dy * dy));
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

double kruskal() {
	int cnt = n;
	double res = 0;

	std::sort(edge + 1, edge + 1 + m);

	for (int i = 1; i <= m; i ++) {
		int a = edge[i].a, b = edge[i].b;
		int fa = find(a), fb = find(b);

		double w = edge[i].w;

		if (fa != fb) {
			if (cnt <= k) {
				break;
			}
			p[fa] = fb;
			res = w;
			cnt --;
		}
	}

	return res;
}


int main() {
	std::cin >> n >> k;

	v1.resize(n + 1);

	for (int i = 1; i <= n; i ++) p[i] = i;

	for (int i = 1; i <= n; i ++) {
		std::cin >> v1[i].ff >> v1[i].ss;
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < i; j ++) {
			edge[++ m] = {i, j, get_dist(i, j)};
		}
	}

	printf("%.2lf", kruskal());
}