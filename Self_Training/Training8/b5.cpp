#include <bits/stdc++.h>
#include <cctype>

using i64 = long long;

int main() {
	i64 n;
	while(std::cin >> n) {
		std::set<i64> s1;
		std::vector<i64> v;
		v.push_back(n);
		i64 num, cnt = 0;

		while(1) {
			if(s1.find(n) != s1.end()) {
				num = n;
				break;
			}
			
			s1.insert(n);

			std::vector<i64> v1, v2;

			while(n) {
				v1.push_back(n % 10);
				n /= 10;
			}
			
			sort(v1.begin(), v1.end());

			v2 = v1;

			std::reverse(v2.begin(), v2.end());

			i64 a = 0, b = 0;

			for(int i = 0; i < v2.size(); i ++) {
				a = a * 10 + v2[i];
				b = b * 10 + v1[i];
			}
			n = a - b;	
			v.push_back(n);
			cnt ++;
		}

		bool ok = false;
		for(int i = 0; i < cnt; i ++) {
			if(v[i] == num) ok = true;
			if(ok) std::cout << v[i] << " \n"[i == cnt - 1];
		}
	}
}