#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

const int N = 1e5 + 10;



void solve() {
	int c1, c2, k; 
	
	std::cin >> c1 >> c2 >> k;
	
	std::vector<int> v1, v2, cnt(3000, 0);
	
	for (int i = 1; i <= c1; i ++) {
		int x; std::cin >> x, v1.push_back(x);

	}
	
	for (int i = 1; i <= c2; i ++) {
		int x; std::cin >> x, v2.push_back(x);
	}
	
	int ans = 0, sz = 0;
	
	while (v1.size() && v2.size()) {
		int num[2] = {-1, -1};
		
		if (v1.size()) num[0] = v1.back(), v1.pop_back();
		if (v2.size()) num[1] = v2.back(), v2.pop_back();
		
		for (int i = 0; i <= 1; i ++) {
			if (~num[i]) continue;
			
			cnt[num[i]] ++;
			
			sz ++;
			
			if (cnt[num[i]] == k) sz -= k, cnt[num[i]] = 0;
			
			ans = std::max(ans, sz);
		}
	}
	
	std::cout << ans << "\n";
}

int main() {
	int _;
	
	std::cin >> _;
	
	while (_ --) {
		solve();
	}
}
