#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
#define ll long long
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N = 1e5 + 10; 

ll w[N];

int n, m, k;

struct node{
	ll l, r;
	double sum, add;
}tr[4 * N];

void pushup(int p){
	tr[p].sum = tr[rc].sum + tr[lc].sum;
}
void pushdown(int p){
	if (tr[p].add){
		tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
		tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
		tr[p].add = 0;
	}
}
void build(int p, int l, int r){
	tr[p] = {l, r, w[l] * 1.0, 0.0};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}
void update(int p, int l, int r, int k){
	if (tr[p].l >= l && tr[p].r <= r){
		tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
		tr[p].add += k;
		return;
	}
	int m = tr[p].l + tr[p].r >> 1;
	pushdown(p);
	if (l <= m) update(lc, l, r, k);
	if (r > m) update(rc, l, r, k);
	pushup(p);
}
ll query(int p, int l, int r){
	if (tr[p].l >= l && tr[p].r <= r)
		return tr[p].sum;
	int m = tr[p].l + tr[p].r >> 1;
	ll sum = 0;
	pushdown(p);
	if (l <= m) sum += query(lc, l, r);
	if (r > m) sum += query(rc, l, r);
	return sum;
}

int main() {
	std::cin >> n >> m >> k;

	for (int i = 1; i <= m; i ++) {
		int op, l, r, x;

		std::cin >> op >> l >> r;

		if (op == 1) {
			std::cin >> x;
			update(1, l, r, x);
		} else {
			update(1, l, r, -1);
		}
	}
}

