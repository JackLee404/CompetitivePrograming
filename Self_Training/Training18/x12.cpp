#include <iostream>
#include <algorithm>
#define lc p<<1
#define rc p<<1|1
using i64 = long long;

const int N = 2e5 + 10;

struct Line {
	int x, y1, y2;
	int flag;
	bool operator<(Line &b) {return x < b.x;}
} L[N];

struct node {
	int l, r, len;
	int cnt;
} tr[8 * N];

int n, Y[N];

void pushup(int p) {
	if (tr[p].cnt) tr[p].len = tr[p].r - tr[p].l;
	else tr[p].len = tr[lc].len + tr[rc].len;
}

void build(int p, int l, int r) {
	tr[p].l = Y[l], tr[p].r = Y[r];
	if (r == l + 1) return;
	int mid = l + r >> 1;
	build(lc, l, mid);
	build(rc, mid, r);
}

void change(int p, int a, int b, int c) {
	if (a >= tr[p].r || b <= tr[p].l) return;
	if (a <= tr[p].l && tr[p].r <= b) {
		tr[p].cnt += c;
		pushup(p);
		return;
	}
	change(lc, a, b, c);
	change(rc, a, b, c);
	pushup(p);
}

int main() {
	int n;
	std::cin >> n;

	for (int i = 1; i <= n; i ++) {
		int x1, y1, x2, y2;
		std::cin >> x1 >> y1 >> x2 >> y2;
		L[i] = {x1, y1, y2, 1}, L[i + n] = {x2, y1, y2, -1};
		Y[i] = y1, Y[i + n] = y2;
	}

	n *= 2;	

	std::sort(L + 1, L + n + 1);
	std::sort(Y + 1, Y + n + 1);

	build(1, 1, n);
	
	i64 ans = 0;

	for (int i = 1; i < n; i ++) {
		change(1, L[i].y1, L[i].y2, L[i].flag);
		ans += 1LL * (L[i + 1].x - L[i].x) * tr[1].len;
	}

	std::cout << ans;
}