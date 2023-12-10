#include <iostream>

using i64 = long long;

const int N = 1e5 + 10;

int n, p;

int h[N], ne[N], e[N], idx;

void add(int a, int b) {
	
}

int main() {
	std::cin >> n >> p;

	for(int i = 1; i <= p; i ++) {
		int x, y;

		std::cin >> x >> y;

		add(x, y);
	}
}