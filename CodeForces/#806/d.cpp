#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
using namespace std;
const int N = 1e5 + 10;
// inline void Out(int x){
// 	int i = 0, t = x;
// 	while (t != 0) t /= 2, i ++;
// 	for (; i >= 0; i --){
// 		cout << (x >> i & 1);
// 	}
// 	cout << "\n";
// }
string a[N];
inline void solve(){
	int n;
	set<string> s1;
	cin >> n;
	rep (i, 1, n){
		cin >> a[i];
		s1.insert(a[i]);
	}
	string res;
	rep (i, 1, n){
		bool ok = false;
		for (int j = 0; j < a[i].size(); ++ j){
			string x = a[i].substr(0, j), y = a[i].substr(j);
			if (s1.count(x) && s1.count(y)) {
				ok = true;
				break;
			}
		}
		res.push_back(ok ? '1' : '0');
	}
	cout << res << endl;
}
 
 
int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}
