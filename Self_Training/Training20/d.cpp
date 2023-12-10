#include <bits/stdc++.h>

using i64 = long long;

int main() {
	std::string t;

	std::cin >> t;

	int len = t.size();

	char last = t[0];

	bool ok = true;

	for (int i = 1; i < len; i ++) {
		if (isupper(t[i - 1])) {
			if (tolower(t[i - 1]) != t[i] && t[i - 1] - 1 != t[i]) {
				ok = false;
			}
		} else {
			if (toupper(t[i - 1]) != t[i] && t[i - 1] + 1 != t[i]) {
				ok = false;
			}
		}
	}

	puts(ok?"Y":"N");
}