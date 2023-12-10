#include <iostream>
#include <algorithm>

using i64 = long long;

std::string get(i64 a, i64 b, int n) {
	i64 t = a * b;

	std::string ans;

	if (t == 0) {
		return "0";
	}

	while (t > 0) {
		int k = t % n;

		if (k < 10) ans.push_back(k + '0');
		else {
			ans.push_back(k - 10 + 'A');
		}

		t /= n;
	}

	std::reverse(ans.begin(), ans.end());

	return ans;
}

std::string trans(int x) {
	std::string ans;

	if (x >= 10) {
		ans.push_back(x - 10 + 'A');
	} else ans.push_back(x + '0');

	return ans;
}

int main() {
	int n;

	std::cin >> n;

	// std::cout << get(3, 2, 4);

	for (int i = 1; i < n; i ++) {
		for (int j = 1; j <= i; j ++) {
			printf("%s*%s=%s", trans(i).c_str(), trans(j).c_str(), get(i, j, n).c_str());
			std::cout << " \n"[j == i];
		}
	}
}