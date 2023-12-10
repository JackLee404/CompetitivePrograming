#include <iostream>
#include <algorithm>

using i64 = long long;

const int N = 5e4 + 10;

struct node {
	int x, y, r;
}a[N], b[N];

bool st[N];

int n, m;

int dist(int x1, int y1, int x2, int y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) {
		int x, y, r;

		std::cin >> x >> y >> r;

		a[i] = {x, y, r};
	}

	for(int i = 1; i <= m; i ++) {
		int x, y, r;

		std::cin >> x >> y >> r;

		b[i] = {x, y, r};
	}

	std::sort(a + 1, a + 1 + n, [](node a, node b) {
		if(a.x == b.x)
			return a.y < b.y;
		else
			return 
	});
}