#include <iostream>
#define lowbit(x) (x & -x)
using i64 = long long;

const int N = 1e5 + 10;

int n, m, a[N];

i64 tr1[N], tr2[N];

void add(i64 tr[], int x, i64 c) {
	for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

i64 query(i64 tr[], int x) {
	i64 res = 0;
	for (int i = x; i; i -= lowbit(i)) res += tr[i];
	return res;
}

i64 prefix(int x) {
	return query(tr1, x) * (x + 1) - query(tr2, x);
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		add(tr1, i, a[i] - a[i - 1]);
		add(tr2, i, (i64)i * (a[i] - a[i - 1]));
	}

	while (m --) {
		char op[2];
		int l, r, x;

		scanf("%s%d%d", op, &l, &r);

		if (op[0] == 'C') {
			scanf("%d", &x);
			add(tr1, l, x), add(tr1, r + 1, -x);
			add(tr2, l, (i64) l * x), add(tr2, r + 1, (i64) (r + 1) * -x);
		} else {
			std::cout << prefix(r) - prefix(l - 1) << "\n";
		}
	}
}