#include <bits/stdc++.h>

using i64 = long long;

//出现两个相同的串 abab

void solve() {
	int n;
	std::map<std::string, int> mp;
	std::string t;
	std::cin >> n >> t;

	bool ok = false;
	for(int i = 0; i < n; i ++) {
		if(i < n - 1) {
			std::string s;
			s.append(t, i, 2);
			if(mp.find(s) != mp.end()) {
				// std::cout << s << " " << mp[s] << " " << i << std::endl;
				if(mp[s] != i - 1)
					ok = true;	
			} else {
				mp[s] = i;
			}
		}
	}
	puts(ok?"YES":"NO");
}

int main() {
	int _;
	std::cin >> _;
	while(_ --) {
		solve();
	}
}