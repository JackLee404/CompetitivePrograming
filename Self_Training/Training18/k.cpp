#include <bits/stdc++.h>

using i64 = long long;

const int N = 3e4 + 100;

int p[N];

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b) {
	int fa = find(a), fb = find(b);
	p[fb] = fa;
}


void solve() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) p[i] = i;

	for (int i = 1; i <= m; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(b, a);
	}

	// std::set<int> fa;

	for (int i = 1; i <= n; i ++) {
		int k = find(p[i]);
		std::cout << k << " \n"[i == n];
	}
	// puts("");
}

int main() {
	int t;

	std::cin >> t;

	while (t --) {
		solve();
	}
}