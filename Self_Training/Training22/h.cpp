#include <bits/stdc++.h>

using i64 = long long;


std::vector<std::string> v1;


std::set<std::string> s1;

int main() {
	int n;
	std::string t;

	std::cin >> n;

	while (n --) {
		std::cin >> t;

		int cnt1 = 0;

		std::string t2;

		for (int i = 0; i < (int) t.size(); i ++) {
			if (isalpha(t[i])) {
				t2.push_back(t[i]);
				cnt1 ++;
			} else {
				if (cnt1 >= 3 && s1.find(t2) == s1.end()) {
					s1.insert(t2);
					t2[0] = toupper(t2[0]);
					v1.push_back(t2);
				}
				t2.clear();
				cnt1 = 0;
			}
		}
	}

	std::sort(v1.begin(), v1.end(), std::greater<std::string>());

	for (int i = 0; i < v1.size(); i ++) {
		std::cout << v1[i] << " \n"[i == (int)v1.size() - 1];
	}
}