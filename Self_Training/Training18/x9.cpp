#include <iostream>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 2e5 + 10;

int w[N];

struct node {
    i64 l, r, mx, add;
} tr[4 * N];

void pushup(int p) {
	tr[p].mx = std::max(tr[lc].mx, tr[rc].mx);
}

void pushdown(int p) {
	if (tr[p].add) {
		tr[lc].mx += tr[p].add;
		tr[rc].mx += tr[p].add;
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
		tr[p].add = 0;
	}
}

void build(int p, int l, int r) {
	tr[p] = {l, r, 0, 0};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

void update(int p, int x, int y, int k) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].mx += k;
		tr[p].add += k;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	if (x <= m) update(lc, x, y, k);
	if (y > m) update(rc, x, y, k);

	pushup(p);
}

int query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].mx;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	int res = -1e9;

	if (x <= m) res = std::max(res, query(lc, x, y));
	if (y > m) res = std::max(res, query(rc, x, y));

	return res;
}



int main() {
	int m, p, n = 0;

	std::cin >> m >> p;

	build(1, 1, 2e5 + 1);

	// update(1, 1, 1, 97);

	// std::cout << query(1, 1, 1);

	int last = 0;

	while (m --) {
		std::string op;
		int x;

		std::cin >> op >> x;

		if (op == "A") {
			update(1, ++n, n, ((i64)x + last) % p);
		} else {
			std::cout << (last = query(1, n - x + 1, n)) << "\n";
		}
	}
}