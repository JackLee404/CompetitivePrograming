#include <iostream>
#include <vector>
#include <cstring>

using i64 = long long;

const int N = 1e4 + 10, M = 1e5 + 10;

int n, m;

int p[N], val[N];

int find(int x) {
 	if (p[x] == x || p[p[x]] == p[x]) return p[x];
 	
 	int r = find(p[x]);
 	val[x] += val[p[x]];
 	p[x] = r;

 	return r;
}


int main() {	
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		p[i] = i, val[i] = 0;
	}

	while (m --) {
		int op, a, b;

		std::cin >> op >> a >> b;

		int fa = find(a), fb = find(b);

		if (op == 1) {
			if (fa != fb) {
				p[fa] = fb;
				val[fa] -= val[fb];
			}
		} else {
			val[fa] += b;
		}
	}

	for (int i = 1; i <= n; i ++) {
		std::cout << ((find(i) == i)?(val[i]):(val[i] + val[find(i)])) << " \n"[i == n];
	}
}