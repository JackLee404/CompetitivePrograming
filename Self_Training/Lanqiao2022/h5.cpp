#include <iostream>
#include <unordered_map>
#include <vector>

using i64 = long long;

struct node {
	int x, y, r, l;
} a[500010];

int n, m, cnt, ans = 0;

std::unordered_map<i64, int> idx;

bool b[500010];

i64 calc(i64 x, i64 y) {
	return 1LL * x * (1e9 + 1) + y;
}

inline void dfs(int u) {
	b[u] = true;
	ans += a[u].l;

	for(i64 x = a[u].x - a[u].r; x <= a[u].x + a[u].r; x++) {
		i64 d = 1LL * (x - a[u].x) * (x - a[u].x);
		
		for(i64 y = a[u].y; 1LL * (y - a[u].y) * (y - a[u].y) + d <= 1LL * a[u].r * a[u].r && y <= 1e9; y++) {
			if(idx.find(calc(x, y)) != idx.end()) {
				int k = idx[calc(x, y)];
				if(!b[k])
					dfs(k);
			}
		}

		for(i64 y = a[u].y; 1LL * (y - a[u].y) * (y - a[u].y) + d <= 1LL * a[u].r * a[u].r && y >= 0; y--) {
			if(idx.find(calc(x, y)) != idx.end()) {
				int k = idx[calc(x, y)];
				if(!b[k])
					dfs(k);
			}		
		}
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		int x, y, r;

		std::cin >> x >> y >> r;

		if(idx.find(calc(x, y)) == idx.end()) {
			idx[calc(x, y)] = ++ cnt;
			a[cnt].x = x, a[cnt].y = y, a[cnt].r = r;
		}

		int s = idx[calc(x, y)];

		a[s].r = std::max(a[s].r, r);
		
		a[s].l ++;
	}
	
	for (int i = 1; i <= m; i ++) {
		
		std::cin >> a[cnt + 1].x >> a[cnt + 1].y >> a[cnt + 1].r;

		a[cnt + 1].l = 0;

		dfs(cnt + 1);
	}

	std::cout << ans;
}