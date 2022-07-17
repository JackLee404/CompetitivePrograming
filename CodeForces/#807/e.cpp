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
// int query(int p, int l, int r, int k){
// 	if (t == k && r == k){
// 		return tr[l].n;
// 	}
// 	int m = l + r >> 1;
// 	if (k <= m) query(lc, l, m, k);
// 	if (k > m) query(rc, m + 1, r, k);
// }
void solve(){
	const int ed1 = 200000;
	bitset<N> w;
	int n, q;
	cin >> n;
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
		if (tr[a[k]].n){
			update(1, a[k], a[k], -1);
		} else {
			int t = a[k];
			int nt = lower_bound(a + 1 + k, a + 1 + ed1, 1) - (a + 1);
			update(1, k, nt - 1, 1);
			update(1, a[nt], a[nt], -1);
		}
		if (!tr[l].n) update(1, l, l, 1);
		else {
			int t = a[k];
			int nt = lower_bound(1, a + 1 + l, a + 1 + ed1, 0) - (a + 1);
			update(1, k, nt - 1, -1);
			update(1, a[nt], a[nt], 1);	
		}
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
