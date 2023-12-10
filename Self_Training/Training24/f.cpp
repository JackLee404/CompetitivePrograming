#include <bits/stdc++.h>

using i64 = long long;

int n;

int main() {
	std::cin >> n; getchar();

	while (n --) {
		std::string t;
		std::getline(std::cin, t);

		if (t[(int) t.size() - 1] == '?') {
			if (t.find("PTA") != -1) {
				puts("Yes!");
			} else puts("No.");
		} else {
			puts("enen");
		}
	}
}