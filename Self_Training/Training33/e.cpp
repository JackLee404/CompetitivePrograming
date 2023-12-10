#include <iostream>
#include <cmath>
#include <queue>
#include <map>
#define ff first
#define ss second

using i64 = long long;

const int N = 2e5 + 10;

int n, m, k, q;

int p[N];

std::pair<int, int> b[N];

std::map<std::pair<int, int>, int> mp;

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b) {
	int fa = find(a), fb = find(b);
	p[fa] = fb;
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		p[i] = i;
	}

	for (int i = 1; i <= m; i ++) {
		int u, v;

		std::cin >> u >> v;

		add(u, v);
	}

	std::cin >> k;

	for (int i = 1; i <= k; i ++) {
		std::cin >> b[i].ff >> b[i].ss;
		mp[{find(b[i].ff), find(b[i].ss)}] = mp[{find(b[i].ss), find(b[i].ff)}] = true;
	}

	std::cin >> q;

	for (int i = 1; i <= q; i ++) {
		int x, y;

		std::cin >> x >> y;

		puts(mp[{find(x), find(y)}]?"No":"Yes");
	}
}