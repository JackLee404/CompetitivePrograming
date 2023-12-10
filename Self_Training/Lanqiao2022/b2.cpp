#include <iostream>

using i64 = long long;

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool check(i64 date) {
	std::string t = std::to_string(date);
	int sz = t.size();
	for(int i = 2; i < sz; i ++) {
		if(t[i] - t[i - 1] == 1 && t[i - 1] - t[i - 2] == 1) {
			return true;
		}	
	}
	return false;
}

int main() {
	// 测试闰年， 非闰年
	// std::cout << ((2022 % 4 == 0 && 2022 % 100 != 0) || (2022 % 400) == 0);
	int ans = 0;

	for(int i = 1; i <= 12; i ++) {
		for(int j = 1; j <= day[i]; j ++) {
			i64 date = 2022 * 10000 + i * 100 + j;

			if(check(date)) {

				// std::cout << date << "\n";
				ans ++;
			}
		}
	}	

	std::cout << ans << "\n";
}