#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
using namespace std;
void solve(){
	int n;
	long long a[1010], dp[1010];
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
