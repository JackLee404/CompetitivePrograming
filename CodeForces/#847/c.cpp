#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;
	std::cin >> n;

	std::vector<i64> val(n + 1);

	std::vector<int> ans(n);

	for(int j = 0; j < n; j ++) ans[j] = j + 1;

	for(int i = 1; i <= n; i ++) {
		for(int j = 1; j < n; j ++) {
			int x;
			std::cin >> x;
			val[x] += j;
		}
	}


	std::sort(ans.begin(), ans.end(), [&val](int &a, int &b) {
		return val[a] < val[b];
	});

	for(int i = 0; i < ans.size(); i ++) {
		std::cout << ans[i] << " \n"[i == ans.size() - 1];
	}
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}