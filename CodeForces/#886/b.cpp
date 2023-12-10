#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n;

	std::cin >> n;

	std::vector<std::pair<int, int>> a;

	for (int i = 1; i <= n; i ++) {
		int x, y;

		std::cin >> x >> y;

		if (x <= 10) {
			a.push_back({y, i});
		}
	}

	std::cout << (*std::max_element(a.begin(), a.end())).second << "\n";
}



int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}