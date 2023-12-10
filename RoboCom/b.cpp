	#include <bits/stdc++.h>
	
	using i64 = long long;
	
	int n, m;
	
	std::map<std::string, char> mp;
	
	int main() {
		std::cin >> n >> m;
		
		for (int i = 1; i <= n; i ++) {
			std::string a;
			
			char c;
			
			std::cin >> a >> c;
			
			mp[a] = c;
		}
		
		while (m --) {
			std::string t, ans;
			
			int l = 0;
			
			std::cin >> t;
			
			bool ok = true;
			
			for (int i = 0; i < t.size(); i ++) {
				std::string s1 = t.substr(l, i - l + 1);
				
				if (mp.count(s1)) {
					ans.push_back(mp[s1]);
					l = i + 1;
				}
			}
			
			if (l != t.size()) {
				if (mp.count(t)) {
					std::cout << mp[t];
				} else std::cout << "D";
			} else std::cout << ans;
	 		
			puts("");
		}
	}
