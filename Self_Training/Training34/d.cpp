#include <bits/stdc++.h>

using i64 = long long;

int year = 1900;

int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(std::string t) {
	for (auto &x: t) {
		if (x == '2') {
			return true;
		}
	}
	return false;
}

int main() {
	i64 res = 0;

	for (int i = year; i <= 9999; i ++) {
		if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
			days[2] = 29;
		} else days[2] = 28;

		for (int j = 1; j <= 12; j ++) {
			for (int k = 1; k <= days[j]; k ++) {
				std::string date = std::to_string(i) + std::to_string(j) + std::to_string(k);		

				// std::cout << date << "\n";
				if (check(date)) {
					res ++;
				}
			}
		}	
	}

	std::cout << res;
}