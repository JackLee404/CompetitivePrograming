#include <bits/stdc++.h>
#include <cctype>
using namespace std;
 
void solve(){
	string a;
	cin >> a;
	if (tolower(a[0]) == 'y' && tolower(a[1]) == 'e' && tolower(a[2])  == 's'){
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;
}
 
 
int main(){
	int t;
	cin >> t;
	while(t --){
		solve();
	}
}
