/*
	Don't know how to solve it.
*/
#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
#define ll long long
#define lc p<<1
#define rc p<<1|1
using namespace std;
const int N = 1e6 + 10; 
ll w[N];
struct node{
	ll l, r, sum, x, add;
}tr[4 * N];
void pushup(int p){
//	tr[p].sum = tr[rc].sum + tr[lc].sum;
	if (tr[rc].sum == tr[lc].sum) {
		tr[p].x = tr[rc].x + tr[lc].x;
	} else {
		if (tr[rc].x == tr[lc].x) {
			tr[rc].x
		}
	}
}

//void pushdown(int p){
//	if (tr[p].add){
//		tr[rc].sum += (tr[rc].r - tr[rc].l + 1) * tr[p].add;
//		tr[lc].sum += (tr[lc].r - tr[lc].l + 1) * tr[p].add;
//		tr[lc].add += tr[p].add;
//		tr[rc].add += tr[p].add;
//		tr[p].add = 0;
//	}
//}

void build(int p, int l, int r){
	tr[p] = {l, r, w[l], 1, 0};
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
//	pushdown(p);
	if (l <= m) sum += query(lc, l, r);
	if (r > m) sum += query(rc, l, r);
	return sum;
}
int main()
{
//	int n, m;
//	cin >> n >> m;
//	rep (i, 1, n){
//		cin >> w[i];
//	}
//	build(1, 1, n);
//	rep (i, 1, m){
//		int c, x, y, z;
//		cin >> c;
//		if (c == 1){
//			cin >> x >> y >> z;
//			update(1, x, y, z);
//		}
//		else{
//			cin >> x >> y;
//			cout << query(1, x, y) << endl;
//		}
//	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i ++) {
		cin >> w[i];
	}
	int t;
	while (t --) {
		string s1;
		int a, b;
		cin >> s1 >> a >> b;
		if (s1 == "query") {
			cin >> a >> b;
		} else if (s1 == "set") {
			int c;
			cin >> c;
		}
	}
}
