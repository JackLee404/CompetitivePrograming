#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;
const int N = 110;
inline void solve(){
	char a[N][N];
	int n;
	cin >> n;
	rep (i, 1, n) scanf("%s", a[i] + 1); 
	int ed, ans = 0;
	if (n % 2 == 0) ed = n / 2;
	else ed = n / 2 + 1;
	rep (i, 1, ed)
		rep (j, 1, ed){
			int cnt = 0, x = i, y = j;
			rep (k, 1, 4){
				int ox = x, oy = y;
				cnt += a[x][y] == '0';
				x = oy, y = n - ox + 1;
			}
			if (cnt == 0 || cnt == 4) continue;
			ans += min(4-cnt, cnt);
			char t = cnt > 2 ? '1' : '0';
			x = i, y = j;
			rep (k, 1, 4){
				int ox = x, oy = y;
				a[x][y] = t;
				x = oy, y = n - ox + 1;
			}
		}
	cout << ans << endl;
}

int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}

/*
	https://codeforces.com/contest/1703/problem/E
*/
