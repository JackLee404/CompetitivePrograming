#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

int n, ans = -1;
map<int, vector<int>> mp;
map<int, bool> st;

void dfs(int u) {
	ans = max(ans, u);
	vector<int> &b = mp[u];
	for (int i = 0; i < b.size(); i ++) {
		if (!st[b[i]]) {
			st[b[i]] = true;
			dfs(b[i]);
		}
	}
}	

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		int a, b;
		cin >> a >> b;
		mp[a].push_back(b), mp[b].push_back(a);
	}
	dfs(1);
	cout << ans;
}