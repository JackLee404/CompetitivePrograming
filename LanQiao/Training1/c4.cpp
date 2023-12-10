#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 1e5 + 3;

int h[N], e[N], ne[N], idx;

void insert(int x) {
	int k = (x % N + N) % N;

	ne[idx] = h[k], h[k] = idx, e[idx ++] = x;
}

bool find(int x) {
	int k = (x % N + N) % N;

	for(int i = h[k]; i != -1; i = ne[i]) {
		if(e[i] == x) return true;
	}

	return false;
}

int main() {
	memset(h, -1, sizeof h);
	int _;
	std::cin >> _;

	while(_ --) {
		std::string op;
		int x;

		std::cin >> op >> x;

		if(op == "I") {
			insert(x);
		} else {
			puts(find(x)?"Yes":"No");
		}
	}
}