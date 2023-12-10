#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::string t;
	
	std::cin >> t;
	
	int n;
	
	std::cin >> n;
	
	while (n --) {
		int st, ed;
		std::string st2, ed2;
		
		std::cin >> st >> ed >> st2 >> ed2;
		
		std::string t2 = t, cp;
		
		int len = t.size();
		
		cp = t2.substr(st - 1, ed - st + 1);
		
		t = t2.substr(0, st - 1) + t2.substr(ed, len - ed);
		
		len = t.size();
		
		int st3, ed3;
		
		st3 = t.find(st2), ed3 = t.find(ed2);
		
		int st33 = st3, ed33 = ed3;
		
		ed3 += ed2.size() - 1;
		st3 += st2.size() - 1;
		
//		std::cout << st3 

		if (st3 == -1 || ed3 == -1) {
			t = t + cp;
			continue;
		}
		
		t = t.substr(0, st3 + 1) + cp + t.substr(ed33, len - ed33);
		
//		std::cout << t << "\n";
	}
	
	std::cout << t;
}