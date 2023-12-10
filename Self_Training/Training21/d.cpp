#include <iostream>
#include <cctype>

using i64 = long long;

int main() {
	std::string t, ans;

	std::cin >> t;

	int len = t.size();

	for (int i = 0; i < len; i ++) {
		if (i && isdigit(t[i])) {
			int cnt = t[i] - '0';
			cnt --;
			// std::cout << cnt << "\n";
			while (cnt --) {
				ans.push_back(t[i - 1]);
			}
		} else ans.push_back(t[i]);
	}

	std::cout << ans;
}