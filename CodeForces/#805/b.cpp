#include <bits/stdc++.h>
 
using namespace std;
const int N = 2 * 1e5 + 10;
int main(){
	ios::sync_with_stdio(false);
	int a, b, t, n, path[N], k;
	cin >> t;
	while (t --){
		cin >> n >> k;
		map<int, int> mx1, mi1;
		for (int i = 1; i <= n; i ++){
			cin >> path[i];
			mx1[path[i]] = i;
			if (!mi1[path[i]]) mi1[path[i]] = i;
		} 
		while (k --){
			cin >> a >> b;
			int t1 = mi1[a], t2 = mx1[b];
			if ((!t1 || !t2) || t1 > t2) cout << "no";
			else cout << "yes";
			cout << "\n";
		}
	}
}
 
/*
  https://codeforces.com/contest/1702/problem/B
*/
