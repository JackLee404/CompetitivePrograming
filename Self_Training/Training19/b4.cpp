#include <iostream>
#define lc p<<1
#define rc p<<1|1
using i64 = long long;

const int N = 2e5 + 10;

int n, m;

struct node {
	int l, r, sum, add;
} tr[4 * N];

int w[N];

void pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {
	if (tr[p].add) {
		tr[lc].sum = (tr[lc].r - tr[lc].l + 1) - tr[lc].sum;
		tr[rc].sum = (tr[rc].r - tr[rc].l + 1) - tr[rc].sum;
		tr[lc].add ^= 1;
		tr[rc].add ^= 1;
		tr[p].add = 0;
	}
}

void build(int p, int l, int r) {
	tr[p] = {l, r, w[l], 0};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

void update(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].sum = (tr[p].r - tr[p].l + 1) - tr[p].sum; 
		tr[p].add ^= 1;
		return;
	}	

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	if (x <= m) update(lc, x, y);
	if (y > m) update(rc, x, y);

	pushup(p);
}

int query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].sum;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	int cnt = 0;

	if (x <= m) cnt += query(lc, x, y);
	if (y > m) cnt += query(rc, x, y);

	return cnt;
}

int main() {
	std::cin >> n >> m; 

	for (int i = 1; i <= n; i ++) {
		char c;
		std::cin >> c;
		w[i] = c - '0';
	}

	build(1, 1, n);

	while (m --) {
		int op, l, r;

		std::cin >> op >> l >> r;

		if (!op) {
			update(1, l, r);
		} else {
			std::cout << query(1, l, r) << "\n";
		}
	}
}