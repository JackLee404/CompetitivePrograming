#include <bits/stdc++.h>

using i64 = long long;

const int N = 2e5 + 10;

std::string t1;

std::vector<std::string> vec;

std::map<int, int> mp;

i64 ans1, ans2;

int type[N];

void split(std::string s1) {
	int len = s1.size(), cnt = 0;

	std::string t;

	type[++ cnt] = 1;

	for (int i = 0; i < len; i ++) {
		if (s1[i] != '+' && s1[i] != '-') {
			t.push_back(s1[i]);
		} else {
			if (!t.size()) continue;
			type[++ cnt] = (s1[i] == '+')?1:-1;
			vec.push_back(t);
			t.clear();
		}
	}
	
	if (t.size())
		vec.push_back(t);
}

void solve() {
	int t = 0;

	for (auto &s1: vec) {
		int pos = s1.find("d");
 
		t ++;

		if (pos == -1) {
			ans1 += std::stoi(s1.c_str()) * type[t];
			ans2 += std::stoi(s1.c_str()) * type[t];
			continue;
		}

		if (!pos) {
			i64 t2 = std::stoi(s1.substr(1, (int) s1.size() - 1).c_str());
			mp[std::stoi(s1.substr(1, (int) s1.size() - 1).c_str())] += 1;

			if (type[t] == 1) {
				ans1 += 1;
				ans2 += t2;
			} else {
				ans1 -= t2;
				ans2 -= 1;
			}

			continue;
		}

		i64 t1 = std::stoi(s1.substr(0, pos).c_str()), t2 = std::stoi(s1.substr(pos + 1, (int) s1.size() - pos).c_str());

		int mx1 = t2 * t1, mi1 = t1;

		if (type[t] == 1) {
			ans1 += mi1;
			ans2 += mx1;
		} else {
			ans1 -= mx1;
			ans2 -= mi1;
		}

		mp[t2] += t1;
	}	
}

int main() {
	std::cin >> t1;

	if (t1[0] == '+' || t1[0] == '-') {
		t1 = "0" + t1;
	}

	split(t1);

	solve();

	for (auto x: mp) {
		std::cout << x.first << " " << x.second << "\n";
	}

	std::cout << ans1 << " " << ans2 << "\n";
}