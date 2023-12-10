#include <iostream>

using i64 = long long;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/*
 20201020
*/

int check(i64 date) {
	std::string t = std::to_string(date);

	int len = t.size();

	for (int i = 0, j = len - 1; i < j; i ++, j --) {
		if (t[i] != t[j]) return 0;
	}

	if (t[0] == t[2] && t[1] == t[3]) {
		return 2;
	} else return 2;
}

int main() {
	int n;

	std::cin >> n;

	int start_year = n / 10000;
	int start_day = (n % 10) + (n / 10) % 10 * 10;
	int start_month = (n / 100) % 10 + (n / 1000) % 10 * 10;

	// std::cout << start_year << " " << start_month << " "<< start_day << "\n";
	
	int ans1, ans2;

	ans1 = 0;
	ans2 = 0;

	for (int i = start_year; ; i ++) {
		if ((i % 4 == 0 && i % 400 == 0) && i % 100) days[2] = 29;
		else days[2] = 28;

		for (int j = start_month; j <= 12; j ++) {
			for (int k = start_day; k <= days[j]; k ++) {
				i64 date = 1LL * i * 10000 + j * 100 + k;

				if (i == start_year && j == start_month && k == start_day) continue;

				if(check(date) == 1 && !ans1) {
					ans1 = date;
				} else if(check(date) == 2 && !ans2) {
					ans2 = date;
				}

				if (ans1 && ans2) {
					std::cout << ans1 << "\n" << ans2;
					return 0;
				}

				std::cout << date << "\n";
			}
		}
	}
}