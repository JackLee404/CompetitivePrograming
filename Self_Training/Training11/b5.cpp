#include <iostream>

using i64 = long long;

const int N = 5e4 + 10;

int p[N], d[N], siz[N];

int find(int x) {
	if(p[x] != x) {
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}

void add(int x, int y) {
	int px = find(x), py = find(y);
	if(px != py)
		d[px] = d[y], siz[py] += siz[px];
	p[px] = py;
	
}

int main() {
	int n, t;

	std::cin >> n >> t;

	for(int i = 1; i <= n; i ++) p[i] = i, siz[i] = 1;

	while(t --) {
		std::string t;

		int x, y;

		std::cin >> t >> x >> y;


		if(t == "M") {
			add(x, y);
		} else {
			if(find(x) != find(y)) puts("-1");
			else {
				std::cout << d[x] - d[y] + 1 << "\n";
			}
		}
	}
}