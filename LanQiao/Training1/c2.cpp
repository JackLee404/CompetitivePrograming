#include <iostream>
#define sz(x) (int) x.size()
using i64 = long long;

i64 get2(std::string t1) {
	i64 tot = 0, p = 1;
	for(int i = sz(t1) - 1; i >= 0; i --) {
		tot += (t1[i] - '0') * p;
		p *= 2;
	}
	return tot;
}

i64 get3(std::string t1) {
	i64 tot = 0, p = 1;
	for(int i = sz(t1) - 1; i >= 0; i --) {
		tot += (t1[i] - '0') * p;
		p *= 3;
	}
	return tot;
}

int main() {
	std::string t1, t2;

	std::cin >> t1 >> t2;

	bool f1 = false, f3 = false;

	for(int i = 0; i < sz(t1); i ++) {
		std::string s1 = t1;
		if(t1[i] == '1' && !f1 && sz(t1) != 1) {
			f1 = true;
			continue;
		}
		s1[i] = (s1[i] == '1'?'0':'1');
		i64 val1 = get2(s1);
		for(int j = 0; j < sz(t2); j ++) {
			for(int k = 0; k <= 2; k ++) {
				if(k + '0' == t2[j]) continue;
				if(k == 0 && t2[i] >= '1' && !f3 && sz(t2) != 1) {
					f3 = true;
					continue;
				}
				std::string s2 = t2;
				s2[j] = k + '0';
				i64 val2 = get3(s2);
				if(val1 == val2) {
					return std::cout << val1, 0;
				}
			}
		}	
	}
}