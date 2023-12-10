#include <iostream>
#include <cctype>
#include <string>
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

const int N = 2e5 + 10;

struct node {
	i64 l, r, add, mx;
} tr[4 * N];

int n, m;

int w[N];

void pushup(int p) {
	tr[p].mx = std::min(tr[lc].mx, tr[rc].mx);
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
	tr[p] = {l, r, 0, w[l]};

	if (l == r) return;

	int m = l + r >> 1;

	build(lc, l, m);
	build(rc, m + 1, r);

	pushup(p);
}

i64 query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].mx;
	}

	int m = tr[p].l + tr[p].r >> 1;

	i64 res = 1e18;

	pushdown(p);

	if (x <= m) res = std::min(res, query(lc, x, y));
	if (y > m) res = std::min(res, query(rc, x, y));

	return res;
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

int main() {
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		std::cin >> w[i];
	}

	build(1, 1, n);

	// auto count = [](std::string &t) {
	// 	int res = 0;
	// 	for (auto x: t) {
	// 		if (x == ' ')
	// 			res ++;
	// 	}
	// 	return res;
	// };

	std::cin >> m; getchar();

	while (m --) {
		std::string t;

		std::getline(std::cin, t);

		i64 a[5];
		
		int cnt = 0, last = 0;

		for (int i = 0; i <= (int) t.size(); i ++) {
			if (t[i] == ' ' || !t[i]) {
				a[++ cnt] = atoll(t.substr(last, i - last).c_str());
				last = i + 1;
			}
		}

		a[1] ++, a[2] ++;

		if (cnt == 2) {
			if (a[1] > a[2]) {
				std::cout << std::min(query(1, a[1], n), query(1, 1, a[2])) << "\n";
			} else std::cout << query(1, a[1], a[2]) << "\n";
		} else {
			if(a[1] > a[2]) {
				update(1, a[1], n, a[3]);
				update(1, 1, a[2], a[3]);
			} else update(1, a[1], a[2], a[3]);
		}
	}
}