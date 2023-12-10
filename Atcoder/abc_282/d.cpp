#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

const int N = 2e5 + 10;

int n, m, s1, s2;
int color[N];
vector<int> v1[N];

map<pair<int, int>, bool> mp;

bool ok = true;
void dfs(int u){
	for (auto x : v1[u]){
		if (!color[x]){
			color[x] = (color[u] == 2 ? 1 : 2);
			dfs(x); 
		}else if (color[x] == color[u]) ok = false;
	}		
}

void adds(int a, int b) {
	v1[a].push_back(b);
	v1[b].push_back(a);
	mp[make_pair(a, b)] = true;
	mp[make_pair(b, a)] = true;
}

int main() {
	cin >> n >> m;
	for (int i = 1; i <= m; i ++) {
		int a, b;
		cin >> a >> b;
		adds(a, b);
	}

	for (int i = 1; i <= n; i ++) {
		if (!color[i]) {
			color[i] = 1;
			dfs(i);
		}
	}

	// cout << flag << endl;

	// if (flag) {

	// }

	if (!ok) {
		cout << 0;
		return 0;	
	}

	long long ans = 0;

	for (int i = 1; i <= n; i ++) {
		if (color[i] == 1) 
		for (int j = 1; j <= n; j ++) {
			if (i == j || (color[i] == color[j])) continue;
			if (!mp[make_pair(i, j)]) {
				// cout << i << " " << j << endl;
				adds(i, j), ans ++;
			}
		}	
	}
	cout << ans;
}