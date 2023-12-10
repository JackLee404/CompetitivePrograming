#include <bits/stdc++.h>

using i64 = long long;

int a[20], idx = 1, cnt = -1;

std::string nowin(std::string t) {
	if (t == "ChuiZi")
		return "JianDao";
	else if (t == "JianDao")
		return "Bu";
	else
		return "ChuiZi";
}

std::string win(std::string t) {
	if (t == "ChuiZi")
		return "Bu";
	else if (t == "JianDao")
		return "ChuiZi";
	else
		return "JianDao";
}

int main() {
	int n;

	std::cin >> n;

	for (int i = 1; i <= n; i ++) std::cin >> a[i];

	std::string t;
	
	while (true) {
		std::cin >> t;

		if (t == "End") {
			break;
		}

		if (cnt == -1) {
			cnt = a[idx ++];
			if (idx > n) idx = 1;
		}

		if (cnt != 0) {
			std::cout << win(t) << "\n";
		} else {
			std::cout << nowin(t) << "\n";
		}

		cnt --;
	}
}