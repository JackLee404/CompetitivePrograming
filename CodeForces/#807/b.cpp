#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
using namespace std;
const int N = 2 * 1e5 + 10;
int a[N];
bool cmp(int a, int b) {
	return a > b;
}
void solve(){
	int n;
	long long tot = 0;
	cin >> n;
	rep (i, 1, n) cin >> a[i];
	rep (i, 1, n - 1){
		if (a[i]){
			int j = i + 1;
			while (a[i] && j < n && !a[j]){
				a[j ++] = 1, tot ++, a[i] --;
			}
		}
	}
	// rep (i, 1, n) cout << a[i] << " ";
	// cout << "\n";
	rep (i, 1, n - 1) if (a[i]) tot += a[i];
	cout << tot << endl;
}
 
int main(){
	int _;
	cin >> _;
	while (_--){
		solve();
	}
}
