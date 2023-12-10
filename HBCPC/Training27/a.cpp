#include <bits/stdc++.h>
#define rep(i, j, k) for (int i = j; i <= k; i ++)
using namespace std;

const int N = 600;

int cnt = 0, tot = 0;

vector<int> v[N];

int vis[N], not_exist[N];

int n, m, now;

void dfs(int u) {
	for (auto &x: v[u]) {
		if (!vis[x] && !not_exist[x]) vis[x] = true, dfs(x);
	}
}

int check(int x) {
	memset(vis, 0, sizeof vis);
	int cnt = 1;
	rep (i, 0, n - 1) {
		if (!vis[i]) {
			dfs(i), cnt ++;
		}
	}
	return cnt;
}

int main() {
	cin >> n >> m;
	rep (i, 1, m) {
		int a, b; cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	int q; cin >> q;

	now = check(0);

	while (q --) {
		int t; cin >> t;
		tot ++;
		not_exist[t] = true;
		int k = check(t);

		if (k != now) {
			now = k;
			printf("Red Alert: City %d is lost!", t);
		} else {
			printf("City %d is lost.", t);
		}
		puts("");
		if (tot == n) {
			puts("Game Over.");
		}
	}
}