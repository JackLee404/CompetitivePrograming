#include <iostream>
#include <vector>
#include <unordered_map>
#define siz(a) (int)a.size()
#define rep(i, j, k) for(int i = j; i <= k; i ++)
using namespace std;

const int N = 1e5 + 10;

int n, m, flag = false;
vector<int> pattern, ans;
vector<vector<int>> chip;

void dfs(int u) {
	if (flag) return;
	if (u > n) {
		for (int i = 0; i < siz(ans); i ++) {
			cout << ans[i] << " \n"[i == siz(ans) - 1];
		}
		flag = true;
		return;
	}
	rep (i, 1, siz(chip) - 1) {
		bool check = true;
		if (chip[i][0]) continue;
		for (int j = 1, k = (u == 1?1:u - 1); j < siz(chip[i]) && k <= n; j ++, k ++) {
			if (chip[i][j] != pattern[k]) {
				check = false;
				break;	
			}
		}
		if (check) {
			chip[i][0] = 1;
			ans.push_back(i);
			if (u == 1)
				dfs(u + siz(chip[i]) - 1);
			else
				dfs(u + siz(chip[i]) - 2);
			chip[i][0] = 0;
			ans.pop_back();
		}
	}
}

int main() {
	cin >> n; pattern.resize(n + 1);
	rep (i, 1, n) cin >> pattern[i];
	cin >> m; chip.resize(m + 1);
	rep (i, 1, m) {
		vector<int> tm;
		int k; cin >> k, tm.resize(k + 1), tm[0] = 0;
		rep (j, 1, k) {
			cin >> tm[j];
		}
		chip[i] = tm;
	}
	dfs(1);
}