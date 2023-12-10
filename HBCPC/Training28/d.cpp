#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
#define pii pair<int, int>
#define Inf 0x3f3f3f3f
using namespace std;
const int N = 300;
int d[N][N], n, m, k;
int main() {
    cin >> n >> m;

	rep (i, 1, n)
		rep (j, 1, n)
			if (i == j) d[i][j] = 0;
			else d[i][j] = Inf;

	for(int i = 1; i <= m; i ++) {
		int a, b, c; cin >> a >> b >> c;
		d[a][b] = c;
		d[b][a] = c;
	}
	
    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
            	d[i][j] = max(d[i][j], d[i][k] + d[k][j]), cout << d[i][j] << endl;
    
	int mx2 = Inf, mi2 = 0;
    
	rep(i, 1, n) {
		int mx = -1;
		rep(j, 1, n) {
            if (mx < d[i][j])
			    mx = d[i][j], cout << d[i][j] << endl;
		}
		if(mx2 > mx) {
			mi2 = i, mx2 = mx;
		}
	}
    
    if(mi2 == 0) {
        cout << 0;
    } else cout << mi2 << " " << mx2;
}