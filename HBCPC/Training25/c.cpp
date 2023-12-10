#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

vector<int> v[N];

int ans, mdep;

void dfs(int i, int dep) {
	if (v[i].empty()) {
		if (dep > mdep) {
			ans = i, mdep = dep;
		}
		return;
	}
	for (auto &x: v[i]) {
		dfs(x, dep + 1);
	}
}

int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			int t; cin >> t;
			v[i].push_back(t);
		}
	}
	cout << dep;
}