#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>

// using i64 = long long;

std::string host;

std::map<std::string, int> mp;

std::vector<int> v1, v2;

bool cmp(int a, int b) {
	if(v1[a] == v1[b]) {
		return mp[host] == a;
	} else {
		return v1[a] > v1[b];
	}
}

int main() {
	int n;

	std::cin >> n;

	host = "DaDa";

	for(int i = 1; i <= n; i ++) {
		std::string t;

		std::cin >> t;

		mp[t] = i;
	}

	int m;

	std::cin >> m;

	v1.resize(n + 1), v2.resize(n + 1);

	int cnt;

	for(int i = 1; i <= m; i ++) {
		cnt = 0;
		for(int i = 0; i <= n; i ++) v2[i] = i;

		for(int j = 1; j <= n; j ++) {
			std::string s1;
			int t1;

			std::cin >> t1 >> s1;

			v1[mp[s1]] += t1;

			// std::cout << s1 << " " << mp[s1] << "\n";
		}

		std::sort(v2.begin() + 1, v2.end(), cmp);

		int k = mp[host];

		// for(int i = 1; i <= n; i ++) {
		// 	std::cout << v1[i] << " \n";
		// }

		for(int i = 1; i <= n; i ++) {
			// std::cout << v2[i] << " \n"[i == n];
			if(k == v2[i]) {
				std::cout << i << "\n";
				break;
			}
		}
	}
}