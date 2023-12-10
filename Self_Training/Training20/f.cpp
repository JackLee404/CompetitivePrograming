#include <bits/stdc++.h>

using i64 = long long;

std::map<std::string, int> mp;

int main() {
	int n;

	std::cin >> n;

	std::stack<std::string> a;

	int ans = 0, cnt = 0;

	for (int i = 0; i < n; i ++) {
		std::string x;

		std::cin >> x;

		if (!a.size() || x[0] == '0') {
			if (x[0] != '0') cnt ++;
			a.push(x);
		} else {
			std::string t = a.top();
			if (x[0] == t[0] && x[1] != t[1]) {
				ans ++;
				cnt --;
				a.pop();
				// puts("??");
			} else {
				a.push(x);
				cnt ++;
			}
		}

		std::cout << cnt << "\n";
	}

	std::cout << ans << "\n";
}