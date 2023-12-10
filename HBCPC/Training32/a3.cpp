#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 3200;

int n, m, s, cnt;

vector<int> g[N];

bool vis[N], ok;

void dfs(int u){
	if(cnt == 0) cout << u;
	else cout << " " << u;
	cnt ++;
	vis[u] = true;
	for(auto x: g[u]) {
		if(!vis[x]) {
			dfs(x);
			cout << " " << u;
		}
	}
}

int main() {
	cin >> n >> m >> s;
	for(int i = 1; i <= m; i ++) {
		int a, b;
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	for(int i = 1; i <= n; i ++) {
		sort(g[i].begin(), g[i].end());
	}
	dfs(s);
	if(cnt != n) {
		cout << " 0";
	}
}