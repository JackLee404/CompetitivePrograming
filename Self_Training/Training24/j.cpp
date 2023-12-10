#include <bits/stdc++.h>
#define ff first
#define ss second

using i64 = long long;

int n, m, k;


int main() {
	std::cin >> n;

	std::vector<std::pair<std::string, std::string>> v1(n);

	for (auto &x: v1) {
		std::string t;

		std::cin >> x.ff >> t >> x.ss;
	}

	std::sort(v1.begin(), v1.end());

	for (int i = 0; i < n; i ++) {
		if (!i) {
			if (v1[i].ff != "00:00:00") {
				std::cout << "00:00:00 - " << v1[i].ff << "\n";
			}
		} else {
			if (v1[i].ff != v1[i - 1].ss) {
				std::cout << v1[i - 1].ss << " - " << v1[i].ff << "\n";
			}
		}
	}

	if (v1[n - 1].ss != "23:59:59") {
		std::cout << v1[n - 1].ss << " - " << "23:59:59";
	}
;}