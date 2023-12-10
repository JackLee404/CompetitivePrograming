#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 10;

int n, mxdep;

vector<int> v[N], ans, ns;

void dfs(int u, int dep) {
	if (v[u].empty) {
		if (dep > mxdep) mxdep = dep, ns.copy(ans);
		return;
	}
	for (auto &x: v[u]) {
		ans.push_back(x);
		dfs(x, dep + 1);
		ans.pop_back();
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			int b; cin >> b;
			v[i].push_back(b);
		}
		sort(v[i].begin(), v[i].end());
	}
}