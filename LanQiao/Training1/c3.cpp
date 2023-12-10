#include <iostream>
#include <cstring>

using i64 = long long;

const int N = 2e5 + 3, null = 0x3f3f3f3f;

int h[N];

int find(int x) {
	int k = (x % N + N) % N;
	while(h[k] != null && h[k] != x) {
		k ++;
		if(k == N) k = 0;
	}
	return k;
}

int main() {
	memset(h, 0x3f, sizeof h);
	int n;

	std::cin >> n;

	while(n --) {
		std::string op;
		int x;

		std::cin >> op >> x;

		int pos = find(x);

		if(op == "I") {
			h[pos] = x;
		} else {
			puts(h[pos] == x?"Yes":"No");
		}
	}
}