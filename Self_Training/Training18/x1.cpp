#include <iostream>

using i64 = long long;

int dis[500][500];

void solve() {
	int n, m;	

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dis[i][j] = (i == j?0:0x3f3f3f3f);

	for (int i = 1; i <= m; i ++) {
		int u, v, d;
		
		std::cin >> u >> v >> d;	

		dis[u][v] = std::min(dis[u][v], d);
		dis[v][u] = std::min(dis[v][u], d);
	}

	for (int k = 1; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= n; j ++) {
				dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);	
			}
		}	
	}

	std::pair<int, int> ans;

	ans.first = 0x3f3f3f3f, ans.second = 0;

	for (int i = 1; i <= n; i ++) {
		int t = 0;
		bool ok = true;
		for (int j = 1; j <= n; j ++) {
			if (dis[i][j] >= 0x3f3f3f3f / 2) ok = false;
			else t += dis[i][j];
		}	

		if (ok) ans = std::min(ans, {t, i});
	}

	std::cout << ans.second << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}