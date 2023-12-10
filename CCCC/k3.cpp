#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
#define debug(x) std::cout << "Debug:" << x << "\n";
using i64 = long long;


int main() {
	std::string t;
	
	std::cin >> t;
	
	int n;
	
	std::cin >> n;
	
	while (n --) {
		int st, ed;
		std::string st2, ed2, cp;
		
		std::cin >> st >> ed >> st2 >> ed2;
		
		cp = t.substr(st - 1, ed - st + 1);
		
		t = t.substr(0, st - 1) + t.substr(ed, (int) t.size() - ed);

		int pos1 = t.find(st2 + ed2);
		
		if (pos1 == -1) {
			t = t + cp;
			continue;
		}
		
		t = t.substr(0, pos1 + sz(st2)) + cp + t.substr(pos1 + sz(st2), -1);
	}

	std::cout << t;
}