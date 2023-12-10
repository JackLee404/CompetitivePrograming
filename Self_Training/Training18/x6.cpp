#include <bits/stdc++.h>

using i64 = long long;

std::unordered_map<char, int> h1, h2;

char grp[] = {'A', 'C', 'G', 'T'};

int main() {
	int n;

	std::string t;

	std::cin >> n;

	if (n % 4 != 0) {
		return std::cout << -1, 0;
	}

	std::cin >> t;

	for (int i = 0; i < (int) t.size(); i ++) {
		if (t[i] != '?') {
			h1[t[i]] ++;
			if (h1[t[i]] > n / 4) return std::cout << -1, 0;
		}
	}

	for (int i = 0; i <= 3; i ++) {
		h2[grp[i]] = n / 4 - h1[grp[i]];
	}

	for (int i = 0; i < (int) t.size(); i ++) {
		if (t[i] == '?') {
			for (int k = 0; k <= 3; k ++) {
				if (h2[grp[k]]) {
					h2[grp[k]] --;
					t[i] = grp[k];
					break;
				}
			}
		}
	}

	// if (t.find('?') != -1) {
	// 	return std::cout << -1, 0;
	// }

	std::cout << t;
}

