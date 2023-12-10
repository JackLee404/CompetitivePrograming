#include <iostream>

using i64 = long long;

int main() {
	std::string t, a;

	std::cin >> t >> a;

	int ans = 0;

	auto flip = [](char &x) {
		x = (x == 'o'?'*':'o');
	};

	for(int i = 0; i < (int) t.size() - 1; i ++) {
		if(t[i] == a[i]) continue;

		flip(t[i]), flip(t[i + 1]);

		ans ++;
	}

	std::cout << ans;
}