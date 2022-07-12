#include <bits/stdc++.h>
#include <cctype>
#include <cmath>
#define f first
#define s second
#define rep(i, j, k) for (int i = j; i <= k; ++ i)
using namespace std;
const int N = 2 * 1e5 + 10;
int act(int x){
	while (x % 2 == 0) x /= 2;
	return x;
}
void solve(){
	bool ok = true;
	map<int, int> mp, mp2;
	int n;
	cin >> n;
	rep (i, 1, n){
		int t;
		cin >> t;
		mp[act(t)] ++;
	}
	rep (i, 1, n){
		int t;
		cin >> t;
		if (t % 2 == 0) t = act(t);
		int cnt = mp[t];
		if (!cnt){
			while (!mp[t]){
				t /= 2;
				if (t == 0){
					ok = false;
					break;
				}
			}
			if (ok) mp[t] --;
		}else mp[t] --;
	}
	puts(ok ? "Yes" : "NO");
}

int main(){
	int _;
	cin >> _;
	while (_ --){
		solve();
	}
}

/*
  Basic Number Theory or Trie Tree;
  https://codeforces.com/contest/1702/problem/F
*/
