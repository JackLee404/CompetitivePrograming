#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

vector<int> a[30];

int start, cnt2;

bool st[30];

vector<int> act;

void dfs(int u, int cnt) {
	if (u == start && cnt == 20) {
		cout << ++cnt2 << ":  " << start;
		for (int i = 0; i < act.size(); i ++) {
			cout << " " << act[i];
		}
		cout << endl;
	}
	for (int i = 0; i < a[u].size(); i ++) {
		int v = a[u][i];
		if (!st[v]) {
			st[v] = true;
			act.push_back(v);
			dfs(v, cnt + 1);
			act.pop_back();
			st[v] = false;
		}
	}
}

int main() {
	for (int i = 1; i <= 20; i ++) {
		int b;
		for (int j = 1; j <= 3; j ++) {
			cin >> b;
			a[i].push_back(b);
		}
	}

	for (int i = 1; i <= 20; i ++) {
		sort(a[i].begin(), a[i].end());
	}

	int t;

	while(cin >> t && t) {
		memset(st, 0, sizeof st);
		act.clear();
		cnt2 = 0;
		start = t;
		dfs(t, 0);
	}
}