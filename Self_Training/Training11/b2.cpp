#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int p[N];

int find(int x) {
	if(p[x] != x) p[x] = find(x);
	return p[x];
}

void add(int x, int y) {
	p[find(x)] = find(y);
}

int main() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) p[i] = i;

	for(int i = 1; i <= m; i ++) {
		int a, b;

		std::cin >> a >> b;

		add(a, b);
	}

	int q;

	std::cin >> q;

	while(q --) {
		int x, y;
		std::cin >> x >> y;
		std::cout << (find(x) == find(y)?"Yes":"No") << "\n";
	}
}