#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	std::vector<std::vector<char>> a(9, std::vector<char>(9));


	std::string t;

	for (int i = 1; i <= 8; i ++) {
		for (int j = 1; j <= 8; j ++) {
			std::cin >> a[i][j];
			if (isalpha(a[i][j])) {
				t.push_back(a[i][j]);
			}
		}
	}

	std::cout << t << "\n";
}



int main() {
	int _;

	std::cin >> _;

	while (_ --) { solve(); }
}