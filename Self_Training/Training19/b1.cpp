#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 1e6 + 10;

struct node {
	i64 l, r, sum, tag;
} tr[4 * N];

int w[N];

void pushup(int p) {
	tr[p].sum = std::min(tr[lc].sum, tr[rc].sum);

	if (tr[lc].sum < tr[rc].sum) tr[p].tag = tr[lc].tag;
	else tr[p].tag = tr[rc].tag;
}


void build(int p, int l, int r) {
	tr[p] = {l, r, w[l], l};
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

	res.first = 0x3f3f3f3f;

	if (x <= m) res = std::min(res, query(lc, x, y));
	if (y > m) res = std::min(res, query(rc, x, y));

	return res;
}

int calc(int x) {
	int mx = x % 10, mi = x % 10;

	while (x) {
		mx = std::max(mx, x % 10);
		mi = std::min(mi, x % 10);
		x /= 10;
	}
	return mx - mi;
}

void solve() {
	int l, r;

	std::cin >> l >> r;

	std::cout << query(1, l, r).second << "\n";
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	for (int i = 1; i <= 1e6; i ++) {
		w[i] = calc(i);
	}

	build(1, 1, 1e6);


	int _;

	std::cin >> _;

	while (_ --) {
		solve();
	}
}