#include <bits/stdc++.h>
#include <cctype>
#define other puts("Expression Error!")
#define fa puts("Division By Zero!")

using i64 = long long;

bool get(std::vector<int> &v1, int &k) {
	if(v1.empty()) return false;
	k = v1.back(), v1.pop_back();
	return true;
}

bool get(std::vector<char> &v1, char &k) {
	if(v1.empty()) return false;
	k = v1.back(), v1.pop_back();
	return true;
}

void solve() {
	std::string t;

	std::cin >> t;

	std::vector<int> s1;
	std::vector<char> s2;

	int k1, k2;

	for(int i = 0; i < (int)t.size(); i ++) {
		if(isdigit(t[i])) {
			s1.push_back(t[i] - '0');
		} else {
			char op = t[i];


			if(!get(s1, k1) || !get(s1, k2)) {
				other;
				return;
			}

			if(op == '+') {
			 	k1 = k2 + k1;
			} else if(op == '/') {
				if(!k1) {
					fa;
					return;
				}
				k1 = k2 / k1;
			} else if(op == '*') {
				k1 = k2 * k1;
			} else if(op == '-') {
				k1 = k2 - k1;
			}

			s1.push_back(k1);
		}
	}

	std::reverse(s2.begin(), s2.end());

	if(s1.size() != 1) {
		other;
		return;
	}

		// std::cout << s1.size() << "\n";

	std::cout << s1[0] << "\n";
}

int main() {
	int k;

	std::cin >> k;

	while(k --) {
		solve();
	}
}