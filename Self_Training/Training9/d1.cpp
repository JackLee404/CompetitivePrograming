#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> prefix_fuc(std::string s) {
	int n = (int) s.length();
	std::vector<int> pi(n);
	for(int i = 1; i < n; i ++) {
		int j = pi[i - 1];
		while(j > 0 && s[i] != s[j]) j = pi[j - 1];
		if(s[i] == s[j]) j ++;
		pi[i] = j;
	}
	return pi;
}

int main() {
	std::string s = "abcabcd";

	std::vector<int> a = prefix_fuc(s);

	for(auto t: a) {
		std::cout << t << " ";
	}
}