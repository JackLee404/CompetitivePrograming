#include <iostream>
#include <vector>
#define sz(x) (int)x.size()
// using i64 = long long;

int n, m;

std::vector<std::vector<int> > v1, ans;

const int N = 20;

bool vis[N];

std::vector<int> v;

bool check() {
	for(int i = 0; i < m; i ++) {
		int k = 1;
		if(v1[i][0]) {
			for(int j = 0; k < sz(v1[i]) && j < sz(v); j ++) {
				if(v1[i][k] == v[j]) k ++;
			}
			if(k != sz(v1[i])) return false;
		} else {
			for(int j = 0; k < sz(v1[i]) && j < sz(v); j ++) {
				if(v1[i][k] == v[j]) k ++;
			}
			if(k == sz(v1[i])) return false;
		}
	}
	return true;
}

void dfs(int u) {
	if(u == n + 1) {
		// for(int i = 0; i < sz(v); i ++) {
		// 	std::cout << v[i] << " \n"[i == sz(v) - 1];
		// }
		if(check()) ans.push_back(v);
		return;
	}
	for(int i = 0; i < n; i ++) {
		if(vis[i]) continue;
		vis[i] = true;
		v.push_back(i);
		dfs(u + 1);
		v.pop_back();
		vis[i] = false;
	}
}

int main() {
	std::cin >> n >> m;

	v1.resize(m);

	for(int i = 0; i < m; i ++) {
		int c;

		std::cin >> c;

		v1[i].resize(c + 1);

		for(int j = 1; j <= c; j++) {
			std::cin >> v1[i][j];
		}

		std::cin >> v1[i][0];
	}	

	dfs(1);

	std::cout << sz(ans) << "\n";

	for(int i = 0; i < sz(ans); i ++) {
		for(int j = 0; j < sz(ans[i]); j ++) {
			std::cout << ans[i][j] << " \n"[j == sz(ans[i]) - 1];
		}
	}
}