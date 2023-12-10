#include <iostream>

using i64 = long long;
using ui64 = unsigned long long;

const int N = 1e5 + 10, P = 131;

int n, m;
char str[N];
ui64 h[N], p[N];

ui64 get(int l, int r) {
	return h[r] - h[l - 1] * p[r - l + 1];
}

int main() {
	std::cin >> n >> m >> (str + 1);

	p[0] = 1;

	for(int i = 1; i <= n; i ++) {
		p[i] = p[i - 1] * P;
		h[i] = h[i - 1] * P + str[i];
	}

	while(m --) {
		int l1, r1, l2, r2;

		std::cin >> l1 >> r1 >> l2 >> r2;

		std::cout << (get(l1, r1) == get(l2, r2)?"Yes":"No") << "\n";
	}
}