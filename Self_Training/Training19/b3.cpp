#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdio>
// #define LOCAL
#define lc p<<1
#define rc p<<1|1

using i64 = long long;

struct node {int y, w;} a[50010];
struct node2 {int l, r, mx;} tr[200010];

int n;

void pushup(int p) {
	tr[p].mx = std::max(tr[lc].mx, tr[rc].mx);
	// tr[p].tag = tr[tr[lc].mx > tr[rc].mx?lc:rc].tag;
	// if (a[tr[lc].r].y + 1 != a[tr[rc].l].y) tr[p].ctn = false;
	// else tr[p].ctn = tr[lc].ctn && tr[rc].ctn;
}

void build(int p, int l, int r) {
	tr[p] = {l, r, a[l].w};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}

int query(int p, int x, int y) {
	if (tr[p].l >= x && tr[p].r <= y) {
		return tr[p].mx;
	}

	int m = tr[p].l + tr[p].r >> 1;
	int res = -0x3f3f3f3f;

	if (x <= m) res = std::max(res, query(lc, x, y));
	if (y > m) res = std::max(res, query(rc, x, y));

	return res;
}

// bool query2(int p, int x, int y) {
// 	if (tr[p].l >= x && tr[p].r <= y) {
// 		return tr[p].ctn;
// 	}

// 	int m = tr[p].l + tr[p].r >> 1;
// 	bool res = true;

// 	if (x <= m) res = res && query2(lc, x, y); 
// 	if (y > m) res = res && query2(rc, x, y);

// 	return res;
// }

int fs1(int x) {
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (a[mid].y >= x) r = mid;
		else l = mid + 1;
	}
	return l;
}

int fs2(int y) {
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (a[mid].y <= y) l = mid; 
		else r = mid - 1;
	}
	return l;
}



int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i ++) std::cin >> a[i].y >> a[i].w;

	std::sort(a + 1, a + 1 + n, [](node a, node b) {
		return a.y < b.y;
	});

	build(1, 1, n);

	int m;

	scanf("%d", &m);

	while (m -- ) {
		int x, y;

		scanf("%d%d", &x, &y);
		// 分别求大于等于x的第一个值， 和小于等于y的最后一个值
		int tx = fs1(x), ty = fs2(y);

		if (a[tx].y != x && a[ty].y != y) {
			puts("maybe");
		} else if (a[tx].y != x) {
			if (tx == ty) puts("maybe");
			else if (query(1, tx, ty - 1) >= a[ty].w) puts("false");
			else puts("maybe");

		} else if (a[ty].y != y) {
			if (ty == tx) puts("maybe");
			else if (query(1, tx + 1, ty) >= a[tx].w) puts("false");
			else puts("maybe");
		} else {
			if (a[tx].w < a[ty].w) puts("false");
			else if(ty == tx + 1) {
				if (a[tx].y + 1 == a[ty].y) puts("true");
				else puts("maybe");
			} 
			else if (query(1, tx + 1, ty - 1) >= a[ty].w) puts("false");
			else if (ty - tx == a[ty].y - a[tx].y) puts("true");
			else puts("maybe");
		}
	}
}