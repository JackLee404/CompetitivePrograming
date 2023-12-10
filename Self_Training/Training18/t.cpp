#include <iostream>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 2e5 + 10;

struct node {
	i64 l, r, sum, tag, add;
} tr[4 * N];

int w[N];

void pushup(int p) {
	tr[p].sum = std::max(tr[lc].sum, tr[rc].sum);

	if (tr[lc].sum > tr[rc].sum) tr[p].tag = tr[lc].tag;
	else tr[p].tag = tr[rc].tag;
}


void build(int p, int l, int r) {
	tr[p] = {l, r, w[l], l, w[l]};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

std::pair<i64, i64> query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return {tr[p].sum, tr[p].tag};
	}
	
	int m = tr[p].l + tr[p].r >> 1;
	
	std::pair<i64, i64> res;

	res.first = -0x3f3f3f3f;

	if (x <= m) res = std::max(res, query(lc, x, y));
	if (y > m) res = std::max(res, query(rc, x, y));

	return res;
}

void update(int p, int x, int k) {
	if (tr[p].l == tr[p].r && tr[p].l == x) {	
		tr[p].sum = k;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	if (x <= m) update(lc, x, k);
	if (x > m) update(rc, x, k);

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
			auto t = query(1, b, c);
			std::cout << t.second << " " << t.first << "\n";
		} else {
			update(1, b, c);
		}
	}
}