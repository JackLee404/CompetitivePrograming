#include <bits/stdc++.h>

using namespace std;

int n, p;
vector<int> ans;

void dfs(vector<int> v1) {
	if (v1.empty()) return;
	vector<int> rt, lt;
	// 左子树
	int i = 1;
	while (i < v1.size() && v1[i] < v1[0]) rt.push_back(v1[i ++]);
	while (i < v1.size() && v1[i] >= v1[0]) lt.push_back(v1[i ++]);

	dfs(rt);
	dfs(lt);
	ans.push_back(v1[0]);
}

void dfs2(vector<int> v1) {
	if (v1.empty()) return;
	vector<int> rt, lt;
	// 左子树
	int i = 1;
	while (i < v1.size() && v1[i] >= v1[0]) rt.push_back(v1[i ++]);
	while (i < v1.size() && v1[i] < v1[0]) lt.push_back(v1[i ++]);

	dfs(rt);
	dfs(lt);
	ans.push_back(v1[0]);
}


int main() {
	int n; cin >> n;
	vector<int> v1(n);
	for (auto &x: v1) cin >> x;
	dfs(v1);
	if (ans.size() != n){
		ans.clear(), dfs2(v1);
	}
	if (ans.size() != n) puts("NO");
	else {
		puts("YES");
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << " \n"[i == ans.size()];
		}
	}
}