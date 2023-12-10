#include <iostream>
#include <set>
#include <stack>

using i64 = long long;

const int mod = 1e9 + 7;

std::set<std::string> st1;

// void dfs(int u) {

// }

int main() {
	std::string t;
	std::stack<char> s1;

	std::cin >> t;

	std::string t2 = t;

	int cnt1, cnt2;

	// cnt1代表右边花括号
	cnt1 = cnt2 = 0;

	for(int i = 0; i < t2.size(); i ++) {
		if(t2[i] == '(') {
			s1.push(t2[i]);
		} else {
			if(s1.size()) s1.pop();
			else cnt1 ++;
		}
	}

	cnt2 += s1.size();
	
	// std::cout << cnt1 << " " << cnt2 << "\n";
}