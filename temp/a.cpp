#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;

int n, a[N];

vector<int> ans;

void dfs(int p, int tail) {
//     cout << p << " " << tail << "\n";
	if (p > tail) return;
	int l = p + 1, r = tail;
	while (a[l] < a[p] && l <= tail) l ++;
	while (a[r] >= a[p] && r > p) r --;
//     cout << l << " " << r << "\n";
	if (l - r != 1) return;
	dfs(p + 1, r);
	dfs(l, tail);
	ans.push_back(a[p]);
}


void dfs2(int p, int tail) {
	if (p > tail) return;
	int l = p + 1, r = tail;
	while (a[l] >= a[p] && l <= tail) l ++;
	while (a[r] < a[p] && r > p) r --;
	if (l - r != 1) return;
	dfs2(p + 1, r);
	dfs2(l, tail);
	ans.push_back(a[p]);
}

int main() {
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	dfs(1, n);
	if (ans.size() != n) {
		ans.clear(), dfs2(1, n);
		if (ans.size() != n) {
        	cout << "NO"; return 0;
    	}
	}
    cout << "YES" << "\n";
	for (int i = 0; i < ans.size(); i ++) {
		cout << ans[i] << " \n"[i == (int) ans.size() - 1];
	}
}