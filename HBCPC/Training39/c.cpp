#include <bits/stdc++.h>

using i64 = long long;

/*
	Alice 可以将某个字符 变成 c
	Bob 作出旋转

	hello

	olleh
	olleo

	ab
	cd	
*/

void solve() {
	int n;

	std::string s, t;

	bool ok1 = true, ok2 = false;

	std::cin >> n;

	std::cin >> s >> t;

	if (s == t) return puts("0"), void(0);

	int cnt1 = 0;

	for (int i = 0; i < n; i ++) {
		if (s[i] != t[i]) cnt1 ++;
	}

	std::reverse(s.begin(), s.end());

	if (s == t) return puts("2"), void(0);

	int cnt2 = 0;

	for (int i = 0; i < n; i ++) {
		if (s[i] != t[i]) cnt2 ++;
	}

	std::cout << std::min(2 * cnt1 - (cnt1 % 2 == 1), 2 * cnt2 - (cnt2 % 2 == 0)) << "\n";
}

int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }	
}