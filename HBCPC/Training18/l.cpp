#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

int n, m, sum, mx;
int p[N], d[N];

int dfs(int u) {
	if (p[u] == -1 || d[u] > 0) return d[u];
	sum ++;
	d[u] = dfs(p[u]) + 1;
	return d[u];
}

int main() {
	int t;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> p[i];
	}

	while (m --) {
		cin >> t;	
		mx = max(mx, dfs(t));	
		cout << sum * 2 - mx << endl;
	}
}