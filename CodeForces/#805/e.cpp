#include <bits/stdc++.h>
#include <cstring>
#define f first
#define s second
using namespace std;
const int N = 2 * 1e5 + 10;
vector<int> v[N];
int color[N];
bool ok;
 
void dfs(int u){
	for (auto x : v[u]){
		if (!color[x]){
			color[x] = (color[u] == 2 ? 1 : 2);
			dfs(x); 
		}else if (color[x] == color[u]) ok = false;
	}		
}
 
int main(){
	ios::sync_with_stdio(false);
	int _;
	cin >> _;
	while (_ --){
		memset(color, 0, sizeof(color));
		ok = true;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i ++) v[i].clear();
		for (int i = 0; i < n; i ++){
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i = 1; i <= n; i ++) if (v[i].size() != 2) ok = false;
		if (!ok){
			puts("NO");
			continue;
		}
		for (int i = 1; i <= n; i ++){
			if (!color[i]){
				color[i] = 1, dfs(i);
			}
			if (ok == false) break;
		}
		if (!ok) puts("NO");
		else puts("Yes");
	}
}


/*
	Problem E: After debuggin time, I found my fault in "No" rather than "NO"
	https://codeforces.com/contest/1702/problem/E
*/
