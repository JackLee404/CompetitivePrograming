#include <bits/stdc++.h>
#include <cctype>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);
	int n;
	std::cin >> n;
	for(int i = 1; i <= n; i ++) {
		std::string t;
		std::cin >> t;
		i64 k = std::stoll(t.c_str());
		std::reverse(t.begin(), t.end());
		i64 m = std::stoll(t.c_str());
		std::cout << ((k * k) % m == 0?"Yes":"No") << "\n";
	}
}