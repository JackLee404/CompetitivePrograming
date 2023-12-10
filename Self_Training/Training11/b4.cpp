#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int p[N], siz[N];

int find(int x) {
	if(p[x] != x) p[x] = find(p[x]);
	return p[x];
}

void add(int a, int b) {
	siz[find(b)] += siz[find(a)];
	p[find(a)] = find(b);
}

int main() {
	int n, m;

	std::cin >> n >> m;

	for(int i = 1; i <= n; i ++) p[i] = i, siz[i] = 1;	


	while(m --) {
		std::string act;

		int x, y;

		std::cin >> act;

		if(act == "Q1") {
			std::cin >> x >> y;
			std::cout << (find(x) == find(y)?"Yes":"No") << "\n";
		} else if(act == "Q2") {
			std::cin >> x;
			std::cout << siz[find(x)] << "\n";
		} else {
			std::cin >> x >> y;
			add(x, y);
		}
	}
}