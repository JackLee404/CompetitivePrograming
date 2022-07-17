#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
const int N = 1e5 + 10;
int a[N];
void solve(){
	bool ok = true;
	int n;
	cin >> n;
	rep (i, 1, n) cin >> a[i];
	rep (i, 2, n){
		if (a[i] % a[1] != 0) ok = false; 
	}
	puts(ok ? "YES" : "NO");
}

int main(){
	int _;
	cin >> _;
	while (_--){
		solve();
	}
}
