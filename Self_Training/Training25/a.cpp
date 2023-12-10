#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int n, m, p[N];

i64 calc(int x, int y) {
	return (x - 1) * m + y;
}

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int kruskal() {
	int res = 0;
	
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= m; j ++) {
			int x1 = i - 1, y1 = j, x2 = i, y2 = j;	

			int fa = find(calc(x1, y1)), fb = find(calc(x2, y2));

			if (fa != fb) {
				p[fa] = fb;
				res += 1;
			}
		}
	}

	for (int i = 1; i <= n; i ++) {
		for (int j = 2; j <= m; j ++) {
			int x1 = i, y1 = j - 1, x2 = i, y2 = j;	

			int fa = find(calc(x1, y1)), fb = find(calc(x2, y2));

			if (fa != fb) {
				p[fa] = fb;
				res += 2;
			}
		}
	}

	return res;
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n * m; i ++) p[i] = i;
	
	int x1, y1, x2, y2;

	while (std::cin >> x1 >> y1 >> x2 >> y2){
			
 		int fa = find(calc(x1, y1)), fb = find(calc(x2, y2));

		if (fa != fb) {
			p[fa] = fb;				
		}

	}
	
	std::cout << kruskal();
}