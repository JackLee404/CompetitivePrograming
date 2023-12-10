#include <bits/stdc++.h>

using i64 = long long;

int n, m;

struct node {
	int x1, y1, x2, y2;
} a[100000];

int main() {
	int x, y;

	std::cin >> n >> m >> x >> y;

	for (int i = 1; i <= x; i ++) {
		int x1, y1, x2, y2;

		std::cin >> x1 >> y1 >> x2 >> y2;

		a[i] = {x1, y1, x2, y2};
	}


	while (y --) {
		int x, y;

		std::cin >> x >> y;

		bool ok = false;

		int cnt = 0, last = 1;

		for (int i = 1; i <= n; i ++) {
			int x1 = a[i].x1, x2 = a[i].x2, y1 = a[i].y1, y2 = a[i].y2;
			if (x >= x1 && x <= x2 && y >= y1 && y <= y2) {
				cnt ++;
				last = i;
				ok = true;
			}
		}

		if (ok) {
			std::cout << "Y " << cnt << " " << last << "\n";
		} else {
			puts("N");
		}
	}
}