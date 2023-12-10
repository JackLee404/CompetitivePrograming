#include <bits/stdc++.h>
#include <cmath>
#define INF 0x3f3f3f3f
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
#define debug(x) std::cout << "#debug: " << x << "\n"
#define ff first
#define ss second

using i64 = long long;

const int N = 1e5 + 100;

double a[N];

/*
	设x表示补贴或税金， 保证“才能使商家在这样一种政府预期的价格上，获取相对其他价位上的最大总利润”
	
	对任意的i

	(预期价格 - 成本价格 + x) * 销量x >= (ai - 成本价格 + x) * 销量y
*/


int main() {
	int exp;

	std::cin >> exp;

	int x, y, cost = -1, lx = -1, ly = -1;
	int evep;

	double last_d;

	while(std::cin >> x >> y, !(x == -1 && y == -1)) {
		if(cost == -1) cost = x;

		last_d = (ly - y) * 1.0 / (x - lx);

		if(lx != -1 && x != lx + 1) {
			int pos = lx + 1;

			// debug(pos);

			while(pos < x) {
				a[pos] = ly - (pos - lx) * last_d;
				pos ++;		
			}	
		}

		a[x] = y;
		lx = x, ly = y;
	}

	x = lx, y = ly;
	int pos = lx;

	std::cin >> evep;

	while(y - evep > 0) {
		a[++ pos] = y - evep;
		y -= evep;
 	}
 	
	// FOR(i, cost, pos) {
	// 	std::cout << i << " " << a[i] << "\n";
	// }

	double ans = 0;

	double l = -INF, r = INF;
	
	FOR(i, cost, pos) {
		double k = (i - cost) * a[i] -  (exp - cost) * a[exp];

		k /= (a[exp] - a[i]);

		if(a[exp] - a[i] > 0) {
			l = std::max(l, k);
		} else {
			r = std::min(r, k);	
		}
	}

	if(l > r) {
		std::cout << "NO SOLUTION";
	} else {
		if(l > 0) {
			std::cout << ceil(l);
		} else if (r < 0) {
			std::cout << floor(r);
		} else {
			std::cout << 0;
		}
	}
}