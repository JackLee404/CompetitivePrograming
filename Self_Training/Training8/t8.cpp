#include <bits/stdc++.h>
#define siz(t) (int)t.size()

using i64 = long long;


char a1[] = "NEUQ", a2[] = "neuq";


int main() {
	std::string t;
	std::vector<std::string> ans2;
	int ans = 0;

	while(std::getline(std::cin, t)) {
		if(t == "#") break;
		std::string t2;
		for(int i = 0; i < siz(t); i ++) {
			if(t[i] == 'n'){
				int cnt = 0;
				for(int j = i, k = 0; j < siz(t) && k < 4; j ++, k ++) {
					if(t[j] == a2[k]) cnt ++;
				}
				if(cnt == 4) ans ++;
			} else if(t[i] == 'N') {
				int k = 0, j = i;
				for(; j < siz(t) && k < 4; j ++, k ++) {
					if(t[j] != a1[k]) break;
				}
				if(k == 4) {
					t2 = t2 + "WOW NEUQ";
					i = j;
					continue;
				}
			}
			t2.push_back(t[i]);
		}
		ans2.push_back(t2);
	}

	std::cout << ans << "\n";

	for(auto x: ans2) {
		std::cout << x << "\n";
	}
}