#include <iostream>
#define lowbit(x) (x & -x)

const int N = 1e5 + 10;

using i64 = long long;

int n, m, a[N];
i64 tr[N];

void add(int x, i64 c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

i64 ask(int x) {
	i64 res = a[x];
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];
	
	while (m --) {
		std::string op;
		int x, l, r;

		std::cin >> op;

		if (op == "Q") {
			std::cin >> x;
			std::cout << ask(x) << "\n";
		} else {
			std::cin >> l >> r >> x;
			add(l, x);
			add(r + 1, -x);
		}
	}
}