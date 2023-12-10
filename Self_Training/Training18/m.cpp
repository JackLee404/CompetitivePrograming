#include <bits/stdc++.h>

#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 1e5 + 10;

int n, m, w[N];

struct node {
	int l, r, tag, mx;
} tr[4 * N];

void pushup(int p) {
	tr[p].mx = std::max(tr[lc].mx, tr[rc].mx);

	if (tr[lc].mx > tr[rc].mx) {
		tr[p].tag = tr[lc].tag;
	} else tr[p].tag = tr[rc].tag;
}

void build(int p, int l, int r) {
	tr[p] = {l, r, l, w[l]};

	if (l == r) return;

	int m = l + r >> 1;

	build(lc, l, m);
	build(rc, m + 1, r);

	pushup(p);
}

void update(int p, int pos, int k) {
	if (tr[p].l == tr[p].r && pos == tr[p].l) {
		tr[p].mx = k;
		return;
	}

	int m = tr[p].l + tr[p].r >> 1;

	if (pos <= m) update(lc, pos, k);
	if (pos > m) update(rc, pos, k);

	pushup(p);
}

std::pair<int, int> query(int p, int l, int r) {
	if (tr[p].l >= l && tr[p].r <= r) {
		return {tr[p].mx, tr[p].tag};
	}

	int m = tr[p].l + tr[p].r >> 1;

	int ans = -0x3f3f3f3f, tag = 0;

	std::pair<int, int> t1;

	// std::cout << tr[p].l << " " << tr[p].r << "\n";
	
	if (l <= m) {
		t1 = query(lc, l, m);

		if (t1.first > ans) {
			ans = t1.first;
			tag = t1.second;
		}
	}

	if (r > m) {
		t1 = query(rc, m + 1, r);

		if (t1.first > ans) {
			ans = t1.first;
			tag = t1.second;
		}
	}

	return {ans, tag};
}

int main() {
	std::cin >> n >> m;

	for (int i = 1; i <= n; i ++) std::cin >> w[i];

	build(1, 1, n);

	// update(1, 3, 9);

	// std::cout << query(1, 1, 5).first << " " << query(1, 1, 5).second << "\n";

	// update(1, 5, 9);

	// std::cout << query(1, 1, 5).first << " " << query(1, 1, 5).second << "\n";
	
	for (int i = 1; i <= m; i ++) {
		int x, l, r;

		std::cin >> x >> l >> r;

		if (x == 1) {
			auto t = query(1, l, r);
			std::cout << t.second << " " << t.first << "\n";
		} else {
			update(1, l, r);
		}
	}
}