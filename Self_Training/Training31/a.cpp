// #include <bits/stdc++.h>
#include <iostream>

using i64 = long long;

int n;

int main() {
	std::cin >> n;

	std::string s1, s2;

	std::cin >> s1 >> s2;

	bool ok = true;

	for (int i = 0; i < n; i ++) {
		if (s1[i] == s2[i]) continue;
		else if (s1[i] == '1' && s2[i] == 'l') continue;
		else if (s1[i] == '0' && s2[i] == 'o') continue;
		else if (s1[i] == 'l' && s2[i] == '1') continue;
		else if (s1[i] == 'o' && s2[i] == '0') continue;
		else {
			ok = false;
			break;
		}
	}

	puts(ok?"Yes":"No");
}