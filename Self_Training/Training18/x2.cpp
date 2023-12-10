#include <iostream>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 2e5 + 10;

struct node {
	i64 l, r, sum, add;
} tr[4 * N];

int w[N];

void pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p) {
	if (tr[p].add) {
		tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
		tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
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

i64 query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].sum;
	}

	pushdown(p);
	
	int m = tr[p].l + tr[p].r >> 1;
	i64 res = 0;

	if (x <= m) res += query(lc, x, y);
	if (y > m) res += query(rc, x, y);

	return res;
}

void update(int p, int x, int y, int k) {
	if (tr[p].l >= x && tr[p].r <= y) {	
		tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
		tr[p].add += k;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	if (x <= m) update(lc, x, y, k);
	if (y > m) update(rc, x, y, k);

	pushup(p);
}

int main() {
	int n, q;

	std::cin >> n >> q;

	for (int i = 1; i <= n; i ++) std::cin >> w[i];	

	build(1, 1, n);
	
	while (q --) {
		int a, b, c, d;
		
		std::cin >> a >> b >> c;

		if (a) {
			std::cout << query(1, b, c) << "\n";
		} else {
			std::cin >> d;
			update(1, b, c, d);
		}
	}
}