#include <bits/stdc++.h>

using i64 = long long;

struct tuple {
	int x, y, z;
};

void solve() {
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> a(n, std::vector<int>(m));

	std::vector<int> count(n, 0);

	std::vector<int> nd;

	int cnt1 = 0;

	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			std::cin >> a[i][j];
			cnt1 += a[i][j];
			count[i] += a[i][j];
		}
	}


	if(cnt1 % n != 0){
		std::cout << "-1\n";
		return;
	}
	
	int s = cnt1 / n;

	for(int i = 0; i < n; i ++) {
		if(count[i] < s) {
			nd.push_back(i);
		}
	}

	int ans = 0;

	// std::cout << cnt1 / n << "\n";

	

	std::vector<tuple> curr;

	for(int i = 0; i < n; i ++) {
		int k =	count[i] - cnt1 / n;
		if(k > 0) {
			ans += k;
			if(!nd.size()) continue;
			while(count[i] > s) {
				int pos = nd.back();
				for(int j = 0; j < m; j ++) {
					if(count[pos] == s) break;
					if(!a[pos][j] && a[i][j] && count[i] > s) {
						a[pos][j] = 1;
						a[i][j] = 0;
						curr.push_back({pos, i, j});
						count[pos] ++;
						count[i] --;
					}
				}
				if(count[pos] == s) nd.pop_back();
			}
		}
	}

	std::cout << ans << "\n";
	for(auto &t: curr) {
		std::cout << t.x + 1 << " " << t.y + 1 << " " << t.z + 1 << "\n";
	}
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}