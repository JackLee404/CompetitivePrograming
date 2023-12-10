#include <iostream>
#include <cstdio>
#define INF 0x3f3f3f3f
#define lc p<<1
#define rc p<<1|1
using i64 = long long;

const int N = 5e5 + 10;

char buf[1 << 21], *p1 = buf, *p2 = buf;

inline int read(){
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9'){
        if (ch == '-') w *= - 1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9'){
        s = (s << 1) + (s << 3) + (ch ^ 48);
        ch = getchar();
        return s * w;
    }
}

int w[N];

struct node {
	int l, r, mx, mi, add, tag, b;
	i64 sum;
} tr[4 * N];


void pushup(int p) {
	tr[p].sum = tr[lc].sum + tr[rc].sum;
	tr[p].mx = std::max(tr[lc].mx, tr[rc].mx);
	tr[p].mi = std::max(tr[lc].mi, tr[rc].mi);
	tr[p].b = std::max(tr[lc].b, tr[rc].b);
}

void pushdown(int p) {
}

void build(int p, int l, int r) {
	tr[p] = {l, r, w[l], w[l], 0, INF, w[l], w[l]};
	int m = l + r >> 1;
	build(lc, m + 1, r);
	build(rc, l, m);
	pushup(p);
}

void update1(int p, int x, int y, i64 k) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
		tr[p].add += k;
		if (tr[p].tag != INF) tr[p].tag += k;
		return;
	}
	int m = tr[p].l + tr[p].r >> 1;
	if (x <= m) update1(lc, x, y, k);
	if (y > m) update1(rc, x, y, k);
	pushup(p);
}

void update2(int p, int x, int y, int v) {
	if (tr[p].l >= x && tr[p].r <= y) {
		tr[p].mi = std::min(tr[p].mi, v);
		tr[p].tag = tr[p].mi;
		return;
	}
	int m = tr[p].l + tr[p].r >> 1;
	if (x <= m) update2(lc, x, y, v);
	if (y > m) update2(rc, x, y, v);
	pushup(p);
}

i64 query3(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].sum;
	}
	int m = tr[p].l + tr[p].r >> 1;
	i64 sum = 0;
	pushdown(p);
	if (x <= m) sum += query3(lc, x, y);
	if (y > m) sum += query3(rc, x, y);
	return sum;
}

int query4(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].mx;
	}
	int m = tr[p].l + tr[p].r >> 1;
	int ans = 0;
	pushdown(p);
	if (x <= m) ans = std::max(ans, query4(lc, x, y));
	if (y > m) ans = std::max(ans, query4(rc, x, y));
	return ans;
}

int query5(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].mx;
	}
	int m = tr[p].l + tr[p].r >> 1;
	int ans = 0;
	pushdown(p);
	if (x <= m) ans = std::max(ans, query5(lc, x, y));
	if (y > m) ans = std::max(ans, query5(rc, x, y));
	return ans;
}


int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i++) {
		w[i] = read();
	}

	build(1, 1, n);


}