#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 3e5 + 10;

std::vector<int> g[N];

void solve() {
	int n, m;

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		if (g[i].size()) g[i].clear();
		for (int j = 1; j <= m; j ++) {
			int x;
			std::cin >> x;
			g[i].push_back(x);	
		}
	}

	
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}