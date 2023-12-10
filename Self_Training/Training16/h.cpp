#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>

using i64 = long long;

const int N = 5e4 + 10;

struct node {
	int x, y, r, w;
}p[N];

int n, m, cnt, ans;

bool b[N];

std::unordered_map<i64, int> idx;

i64 calc(int x, int y) {
	return 1LL * x * (1e9 + 1) + y;
}

void dfs(int u) {
	int r = p[u].r;

	b[u] = true;

	ans += p[u].w;

	for (int x = p[u].x - p[u].r; x <= p[u].x + p[u].r; x ++) {
		i64 d = 1LL * (p[u].x - x) * (p[u].x - x);

		for (int y = p[u].y; d + (p[u].y - y) * (p[u].y - y) <= 1LL * r * r; y ++) {
			if (idx.find(calc(x, y)) != idx.end()) {
				int k = idx[calc(x, y)];
				if (!b[k])
					dfs(k);
			}
		}

		for (int y = p[u].y; d + (p[u].y - y) * (p[u].y - y) <= 1LL * r * r; y --) {
			if (idx.find(calc(x, y)) != idx.end()) {
				int k = idx[calc(x, y)];
				if (!b[k])
					dfs(k);
			}
		}
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		int x, y, r;

		std::cin >> x >> y >> r;

		i64 k = calc(x, y);

		if (idx.find(k) == idx.end()) {
			idx[k] = ++ cnt;

			p[cnt].x = x, p[cnt].y = y, p[cnt].r = r, p[cnt].w = 0;
		}

		int v = idx[k];

		p[v].w ++, p[v].r = std::max(p[v].r, r); 
	}

	for (int i = 1; i <= m; i ++) {
		int x, y, r;

		std::cin >> x >> y >> r;

		p[cnt + 1].x = x, p[cnt + 1].y = y, p[cnt + 1].r = r;

		dfs(cnt + 1);
	}

	std::cout << ans;
}