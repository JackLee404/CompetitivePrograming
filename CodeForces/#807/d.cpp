/*
  Thanks to badcw, that help me find the error that a.size() maybe zero!
  and Next time do some cal,
  usigned int should be sensible!!!!!!!!
  (int)unsigned int -+ int
  if usigned int be zero it would be ron out!!!!!
*/
#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
#define per(i, j, k) for (int i = j; i >= k; i --)
#define lc p<<1
#define rc p<<1|1
using namespace std;
typedef long long LL;
const int N = 2 * 1e5 + 10;
int n;
string s, t;
void solve(){
	vector<int> a, b;
	cin >> n;
	cin >> s >> t;
	rep (i, 0, n - 2){
		if (s[i] != s[i + 1])
			a.push_back(i);
		if (t[i] != t[i + 1])
			b.push_back(i);
	}
	if (a.size() != b.size() || s[0] != t[0] || s[n - 1] != t[n - 1]){
		cout << -1 << "\n";
		return;
	}
	LL res = 0;
	rep (i, 0, (int)a.size() - 1){              // rightly this line!!!!!
		res += abs(a[i] - b[i]);
	}
	cout << res << "\n";
	return;
}
 
 
int main(){
	ios::sync_with_stdio(false), cin.tie(0);
	int _;
	cin >> _;
	while (_ --){
		solve();
	}
	return 0;
}
