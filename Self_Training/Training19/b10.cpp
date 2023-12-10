#include <iostream>
#define lc p<<1
#define rc p<<1|1
using i64 = long long;

const int N = 5e5 + 10;

struct node {
	int l, r;
	i64 sum, b;
} tr[4 * N];

i64 w[N];

i64 gcd(i64 a, i64 b) {
	return b?gcd(b, a % b):a;
}
void pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
	tr[p].b = gcd(tr[lc].b, tr[rc].b);
}

void build(int p, int l, int r) {
	tr[p] = {l, r, w[r] - w[r - 1], w[r] - w[r - 1]};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

void update(int p, int x, int y, i64 k) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].b += k;
		tr[p].sum += k;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	if (x <= m) update(lc, x, y, k);
	if (y > m) update(rc, x, y, k);

	pushup(p);
}

i64 query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].b;
	}

	i64 res = 0;

	int m = tr[p].l + tr[p].r >> 1;

	if (x <= m) res = gcd(res, query(lc, x, y));
	if (y > m) res = gcd(res, query(rc, x, y));

	return res;
}

i64 query2(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].sum;
	}

	i64 res = 0;

	int m = tr[p].l + tr[p].r >> 1;

	if (x <= m) res += query2(lc, x, y);
	if (y > m) res += query2(rc, x, y);

	return res;
}


int main() {
	int n, m;

	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	build(1, 1, n);

	while (m --) {
		std::string op;
		int l, r;
		i64 d;

		std::cin >> op >> l >> r;
	
		

		if (op == "C") {
			std::cin >> d;
			update(1, l, l, d);
			if (r + 1 <= n) update(1, r + 1, r + 1, -d);
		} else {
			std::cout << std::abs(gcd(query2(1, 1, l), query(1, l + 1, r))) << "\n";
		}
	}
}