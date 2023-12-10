#include <iostream>
#include <vector>

using i64 = long long;

int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int pday[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

std::vector<int> b, a;

bool prime(int x) {
	if(x < 2) return false;
	for(int i = 2; i <= x / i; i ++) {
		if(x % i == 0) return false;
	}
	return true;
}

void init() {
	for(int i = 1; i <= 12; i ++) {
		for(int j = 0; pday[j] <= day[i]; j ++) {
			if(prime(i * 100 + pday[j])) {
				b.push_back(i * 100 + pday[j]);
			}
		}
	}

	for(int i = 1; i <= 9999; i ++) {
		if(((!(i % 4) && i % 100) ||!(i % 400)) && prime(i * 10000 + 229)) {
			a.push_back(i * 10000 + 229);
		}
	}

	for(int i = 1; i <= 9999; i ++) {
		for(int j = 0; j < b.size(); j ++) {
			if(prime(i * 10000 + b[j])) {
				a.push_back(i * 10000 + b[j]);
			}
		}
	}
}


void solve() {
	std::string t;

	std::cin >> t;
	int ans = 0;

	for(int i = 0; i < a.size(); i ++) {
		bool flag = 1;
		int k = a[i];
		for(int j = 7; j >= 0 && flag; j --, k /= 10) {
			if(t[j] != '-' && k % 10 != t[j] - '0') {
				flag = 0;
			}
		}
		if(flag) ans ++;
	}

	std::cout << ans << "\n";
}

int main() {
	init();

	int _;

	std::cin >> _;

	while(_ --) {
		solve();
	}
}