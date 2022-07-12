#include <bits/stdc++.h>
#include <cstring>
#include <cctype>
using namespace std;
bool st[300];
void solve(){
	memset(st, 0, sizeof(st));
	int n, a[110];
	cin >> n;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= n; i ++){
		int t; string b;
		cin >> t >> b;
		for (auto x : b){
			if (x == 'D') a[i] ++;
			else a[i] --;
			if (a[i] == -1) a[i] = 9;
			if (a[i] == 10) a[i] = 0;
		}
	}
	cout << a[1];
	for (int i = 2; i <= n; i ++) cout << " " << a[i];
	cout << "\n";
}
 
 
int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}
