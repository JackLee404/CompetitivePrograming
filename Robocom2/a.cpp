#include <bits/stdc++.h>

using i64 = long long;

int n;

char another(char x) {
	if (isupper(x)) {
		return x + 1 > 'Z'?'A':x + 1;
	} else if (islower(x)){
		return x - 1 < 'a'?'z':x - 1;
	} else return x;
}

std::string solve(std::string t) {
	int len = t.size();
	
	for (int i = 0; i < len; i ++) {
		t[i] = another(t[i]);
	}
	
	for (int i = 0; i < len;) {
		int cnt = 0;
		
		if (isupper(t[i])) {
			int j = i;
			
			while (j < len && isupper(t[j])) j ++, cnt ++;
			
			if (cnt >= 3) {
				for (int k = i; k < j; k ++) {
					t[k] = tolower(t[k]);
				} 
			}
			
			i = j;
		} else if (islower(t[i])){
			int j = i;
			
			while (j < len && islower(t[j])) j ++, cnt ++;
			
			if (cnt >= 3) {
				for (int k = i; k < j; k ++) {
					t[k] = toupper(t[k]);
				} 
			}
			
			i = j;
		} else i ++;
	}
	
	return t;
}

int main() {
	std::string s;
	
	std::cin >> n >> s;
	
	std::cout << s << "\n";
	
	while (n --) {
		s = solve(s);
	}
	
	std::cout << s;
}
