#include <bits/stdc++.h>

using i64 = long long;

std::vector<int> res;

void solve() {
	int n, s, r;
	std::cin >> n >> s >> r;

	std::cout << s - r;

	n --;

	for(int i = 0; i < (r % n); i ++) {
		std::cout << " " <<  (r / n) + 1;
	}

	for(int i = 1; i <= n - (r % n); i ++) {
		std::cout << " " << r / n;
	}

	std::cout << "\n";
}

int main() {
	int _;
	std::cin >> _;
	while(_ --){
		solve();
	}
}