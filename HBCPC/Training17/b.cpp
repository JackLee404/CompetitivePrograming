#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <ctime>
#include <bitset>
#include <cmath>
#include <sstream>
#include <iostream>
#include <unordered_map>

#define ll long long
#define ull unsigned long long
#define ls nod<<1
#define rs (nod<<1)+1
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define INF 0x3f3f3f3f
#define max(a, b) (a>b?a:b)
#define min(a, b) (a<b?a:b)


const double eps = 1e-10;
const int maxn = 5e5 + 10;
const ll MOD = 99999999999999;


using namespace std;


int a[maxn];
struct segment_tree {
    int l,r;
    int sum,lmax,rmax,ans;
}tree[maxn << 2];


void pushup(int nod) {
    tree[nod].sum = tree[ls].sum + tree[rs].sum;
    tree[nod].lmax = max(tree[ls].lmax,tree[ls].sum + tree[rs].lmax);
    tree[nod].rmax = max(tree[rs].rmax,tree[rs].sum + tree[ls].rmax);
    tree[nod].ans = max(max(tree[ls].ans,tree[rs].ans),tree[ls].rmax + tree[rs].lmax);
}

void build(int l,int r,int nod) {
    tree[nod].l = l,tree[nod].r = r;
    if (l == r) {
        tree[nod].ans = tree[nod].lmax = tree[nod].rmax = tree[nod].sum = a[l];
        return ;
    }
    int mid = (l + r) >> 1;
    build(l,mid,ls);
    build(mid+1,r,rs);
    pushup(nod);
}

void modify(int k,int z,int nod) {
    int l = tree[nod].l,r = tree[nod].r;
    if (l == r) {
        tree[nod].ans = tree[nod].lmax = tree[nod].rmax = tree[nod].sum = z;
        return ;
    }
    int mid = (l + r) >> 1;
    if (k <= mid)
        modify(k,z,ls);
    if (k > mid)
        modify(k,z,rs);
    pushup(nod);
}

segment_tree query(int x,int y,int nod) {
    int l = tree[nod].l,r = tree[nod].r;
    if (x <= l && y >= r)
        return tree[nod];
    int mid = (l + r) >> 1;
    if (y <= mid)
        return query(x,y,ls);
    else if (x > mid)
        return query(x,y,rs);
    else {
        segment_tree le = query(x,y,ls),ri = query(x,y,rs),end;
        end.sum = le.sum + ri.sum;
        end.lmax = max(le.lmax,le.sum + ri.lmax);
        end.rmax = max(ri.rmax,ri.sum + le.rmax);
        end.ans = max(max(le.ans,ri.ans),le.rmax + ri.lmax);
        return end;
    }
}


int main() {
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1;i <= n; i ++)
        cin >> a[i];

    build(1,n,1);

    int mx1 = query(1, n, 1).ans;


    for (int i = 1; i <= n;i ++) {
        cin >> a[i];
    }

    memset(tree, 0, sizeof tree);

    build(1, n, 1);

    int mx2 = query(1, n, 1).ans;

    cout << min(mx1, mx2);
}