#include <vector>
#include <iostream>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 1e5 + 10;

int mod;

i64 w[N];

struct node {
	i64 l, r, sum, add, mul;
} tr[4 * N];

void pushup(int p) {
	tr[p].sum = (tr[lc].sum + tr[rc].sum) % mod;
}

void pushdown(int p) {
	tr[lc].sum = (tr[lc].sum * tr[p].mul + (tr[lc].r - tr[lc].l + 1) * tr[p].add) % mod;
	tr[rc].sum = (tr[rc].sum * tr[p].mul + (tr[rc].r - tr[rc].l + 1) * tr[p].add) % mod;

	tr[lc].add = (tr[lc].add * tr[p].mul + tr[p].add) % mod;
	tr[rc].add = (tr[rc].add * tr[p].mul + tr[p].add) % mod;

	tr[lc].mul = (tr[lc].mul * tr[p].mul) % mod;
	tr[rc].mul = (tr[rc].mul * tr[p].mul) % mod;

	tr[p].add = 0;
	tr[p].mul = 1;
}

void build(int p, int l, int r) {
	tr[p] = {l, r, w[l] % mod, 0, 1};
	if(l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

i64 query(int p, int x, int y) {
	if(tr[p].l >= x && tr[p].r <= y) {
		return tr[p].sum;
	}
	int m = tr[p].l + tr[p].r >> 1;
	i64 sum = 0;
	pushdown(p);
	if (x <= m) sum = (sum + query(lc, x, y)) % mod;
	if (y > m) sum = (sum + query(rc, x, y)) % mod;
	return sum;
}

void update(int p, int x, int y, int k) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) * k) % mod;
		tr[p].add = (tr[p].add + k) % mod;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	if (x <= m) update(lc, x, y, k);
	if (y > m) update(rc, x, y, k);
	
	pushup(p);
}

void update2(int p, int x, int y, int k) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].sum = (tr[p].sum * k) % mod;
		tr[p].mul = (tr[p].mul * k) % mod;
		tr[p].add = (tr[p].add * k) % mod;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	pushdown(p);

	if (x <= m) update2(lc, x, y, k);
	if (y > m) update2(rc, x, y, k);
	
	pushup(p);
}

int main() {
	int n, m;

	std::cin >> n >> m >> mod;

	for (int i = 1; i <= n; i++) {
		std::cin >> w[i];
	}

	build(1, 1, n);


	while (m--) {
		int op, x, y, z;
		
		std::cin >> op >> x >> y;

		if (op == 1) {
			std::cin >> z;
			update2(1, x, y, z);
		} else if (op == 2) {
			std::cin >> z;
			update(1, x, y, z);
		} else if(op == 3) {
			std::cout << query(1, x, y) << "\n";
		}
	}

	return 0;
}