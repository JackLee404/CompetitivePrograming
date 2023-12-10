#include <iostream>
#include <vector>
#include <algorithm>

using i64 = long long;

int days[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 20201020
*/

bool leap(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) return true;
	return false;
}

inline int check(int date) {
	std::string t = std::to_string(date);

	int len = t.size();

	for (int i = 0, j = len - 1; i < j; i ++, j --) {
		if (t[i] != t[j]) return 0;
	}

	if (t[0] == t[2] && t[1] == t[3] && t[0] != t[3]) {
		return 2;
	} else return 1;
}

inline int check(std::string t) {
	// std::string t = std::to_string(date);

	int len = t.size();

	for (int i = 0, j = len - 1; i < j; i ++, j --) {
		if (t[i] != t[j]) return 0;
	}

	if (t[0] == t[2] && t[1] == t[3] && t[0] != t[3]) {
		return 2;
	} else return 1;
}

int main() {
	int n;

	std::cin >> n;

	int sty = n / 10000;
	int stda = (n % 10) + (n / 10) % 10 * 10;
	int stm = (n / 100) % 10 + (n / 1000) % 10 * 10;
	
	int ans1, ans2;

	ans1 = ans2 = 0;

	std::vector<int> v;

	for (int j = 1; j <= 12; j ++) {
		for (int k = 1; k <= days[j]; k ++) {
			int t = j * 100 + k;
			
			int year = (t % 10) * 1000 + (t / 10 % 10) * 100 + (t / 100 % 10) * 10 + (t / 1000 % 10);
			if (j == 2 && k == 29) {
				if (leap(year)) v.push_back(year);
			} else v.push_back(year);
		}
	}

	std::sort(v.begin(), v.end());

	for (auto i: v) {
		if (i < sty) continue;

		int day = (i / 100 % 10) * 10 + (i / 1000);
		int month = (i % 10) * 10 + (i / 10 % 10);
		int t = i * 10000 + month * 100 + day;

		if (t <= n) continue;

		int k = check(t);

		if (k == 2 && !ans2) {
			ans2 = t;
			if (!ans1) ans1 = t;
		}

		if (k == 1 && !ans1) {
			ans1 = t;
		}

		if (ans1 && ans2) break;
	}

	std::cout << ans1 << "\n" << ans2;
}