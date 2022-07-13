/*
	Found erros in the capacity of arr `a` and `dp` that made test 4 wrong, but it didn't notice me that is segement erros but  TLE.
	For every query O(nlogn)
	The second is O(n)
*/
#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
using namespace std;
void solve(){
	int n;
	long long a[200010], dp[200010];
	vector<long long> v;
	memset(dp, 0, sizeof(dp));
	cin >> n;
	for (int i = 1; i <= n; i ++){
		cin >> a[i];
		if (a[i] < i){
			if (v.size()){
				 auto t = lower_bound(v.begin(), v.end(), a[i]);
				 if (t == v.end()) dp[i] = dp[i - 1] + v.size();
				 else {
				 	int x = t - v.begin();
				 	dp[i] = dp[i - 1] + x;
				 }
			}
			v.push_back(i);
		} 
		else dp[i] = dp[i - 1];
	}
	cout << dp[n] << endl;
}


int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}


// second way sum of suffix (Know that i <= 2 * 1e5 and a[i] < n)



#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;

inline void solve(){
	int n, a[200010], b[200010];
	long long dp[200010];
	memset(b, 0, sizeof(b));
	vector<int> v;
	cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i ++){
		scanf("%d", &a[i]);
		if (a[i] < i)
			b[i] = 1;
	}
	rep (i, 1, n) {
		b[i] += b[i - 1];	
		if (a[i] < i && a[i] < n){
			dp[i] = dp[i - 1] + b[a[i] - 1];
		} else dp[i] = dp[i - 1];
	}
	printf("%lld\n", dp[n]);
}


int main(){
	int t;
	scanf("%d", &t);
	while(t --){
		solve();
	}
}

/*
	dp[i][]

*/
