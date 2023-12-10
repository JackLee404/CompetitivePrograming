#include <bits/stdc++.h>

using i64 = long long;

int n, m;

const int N = 1e3, M = 3e4 + 2200;

int a[N];

int main() {
	memset(h, -1, sizeof h);

	std::cin >> m >> n;

	for(int i = 1; i <= n; i ++) {
		int p;
		std::cin >> v[i] >> w[i] >> p;

		w[i] *= v[i];
		
		add(p, i);
	}

	dfs(0);

	std::cout << f[0][m];
}