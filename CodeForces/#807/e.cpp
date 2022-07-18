/*
	I've knwo the way to solve the question, but did not know how to use segement tree to find most right 1 or 0, so the question will be wait to be solved until I learn segement tree all.
*/
#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
const int N = 2 * 1e5 + 10;
int a[N], cnt[N];
struct node{int l, r, n, add;}tr[4 * N];
void pushup(int p){
	tr[p].n = tr[lc].n + tr[rc].n;
}
void pushdown(int p){
	if (tr[p].add){
		tr[rc].n += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
		tr[lc].n += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
		tr[lc].add += tr[p].add;
		tr[rc].add += tr[p].add;
		tr[p].add = 0;
	}
}
void build(int p, int l, int r){
	tr[p] = {l, r, cnt[l], 0};
	if (l == r) return;
	int m = l + r >> 1;
	build(lc, l, m);
	build(rc, m + 1, r);
	pushup(p);
}	
void update(int p, int l, int r, int k){
	if (tr[p].l >= l && tr[p].r <= r){
		tr[p].n += (tr[p].r - tr[p].l + 1) * tr[p].n;
		tr[p].add += k;
		return;
	}
	int m = tr[p].l + tr[p].r >> 1;
	pushdown(p);
	if (l <= m) update(lc, l, r, k);
	if (r > m) update(rc, l, r, k);
	pushup(p);
}
int query(int p, int l, int r, int k){
	if (tr[p].l == k && tr[p].r == k){
		return tr[p].n;
	}
	int m = l + r >> 1;
	if (k <= m) query(lc, l, m, k);
	if (k > m) query(rc, m + 1, r, k);
}
void out1(int p, int l, int r){
	if (l == r){
		cout << tr[p].l << " ";
		return;
	}
	int m = l + r >> 1;
	if (tr[lc].n) out1(lc, l, m);
	if (tr[rc].n) out1(rc, m + 1, r);
}
int mostright(int p, int l, int r){
	if (tr[p].n){
		if (tr[p].l >= l && tr[p].r)
	}
}
void solve(){
	int n, q;
	const int ed1 = 200000;
	cin >> n >> q;
	rep (i, 1, n){
		cin >> a[i];
		cnt[a[i]] ++;
	}
	rep (i, 1, ed1){
		cnt[i + 1] += cnt[i] / 2, cnt[i] %= 2;
	}
	build (1, 1, ed1);
	while (q --){
		int k, l;
		cin >> k >> l;
		int qk = query(1, 1, ed1, a[k]);
		if(qk) update(1, a[k], a[k], -1);
		else update(1, a[k], mright(1, ed1, a[k]))

	}
}

int main(){
	// int _;
	// cin >> _;
	// while (_--){
	// 	solve();
	// }
	solve();
}
