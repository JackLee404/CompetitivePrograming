#include <bits/stdc++.h>

using i64 = long long;

const int N = 500 + 10;

int a[N][N];

bool c[N], r[N];

struct node {
	int x, y, val;

	bool operator<(const node& t) const {
		return val < t.val;

	}

	bool operator>(const node& t) const {
		return val > t.val;
	}
};

void solve() {
	int n;  std::cin >> n;

	memset(c, false, sizeof c);
	memset(r, false, sizeof r);

	i64 ans = 0, ans2 = 0;

	std::priority_queue<node, std::vector<node>, std::greater<node>> heap, h2;

	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			std::cin >> a[i][j];
			if (a[i][j] <= 0) c[j] = r[i] = true, ans += a[i][j], ans2 += a[i][j];
			heap.push({i, j, a[i][j]}), h2.push({i, j, a[i][j]});
		}
	}

	while (heap.size()) {
		auto t = heap.top(); heap.pop();

		if (c[t.y]) continue;

		// std::cout << t.x << " " << t.y << " " << t.val << "\n";

		c[t.y] = true;

		ans += t.val;
	}

	while (h2.size()) {
		auto t = h2.top(); h2.pop();

		if (r[t.x]) continue;

		// std::cout << t.x << " " << t.y << " " << t.val << "\n";

		r[t.x] = true;

		ans2 += t.val;
	}

	std::cout << std::min(ans2, ans) << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}