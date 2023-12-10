#include <iostream>
#include <vector>
#define lc p<<1
#define rc p<<1|1

const int N = 1e5 + 10,  mod = 571373;

using i64 = long long;

int n, w[N];

struct node {
	i64 l, r, tag, add;
}tr[4 * N];

void pushdown(int p) {
	if (tr[p].add) {
		tr[lc].add = tr[p].add;		
		tr[rc].add = tr[p].add;
		tr[p].add = 0;
	}
}

void pushup(int p) {

}

void build(int p, int l, int r) {
	tr[p] = {l, r, 0, 0};

	if(l == r) return;

	int m = l + r >> 1;

	build(lc, l, m);
	build(rc, m + 1, r);

	pushup(p);
}

i64 query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].tag;
	}

	int m = tr[p].l + tr[p].r >> 1;
	i64 sum = 0;

	pushdown(p);

	if (x <= m) sum += query(lc, x, y);

	if (y > m) sum += query(rc, x, y);

	return sum;
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
	int n, m;

	std::cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}

	build(1, 1, n);

	while (m--) {
		int x, y;

		std::cin >> x >> y;

		if (x == 1) {

		} else {

		}
	}
}
