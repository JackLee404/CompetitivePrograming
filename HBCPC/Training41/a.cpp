#include <bits/stdc++.h>

using i64 = long long;

void solve() {
	int n, k;

	std::cin >> n >> k;

	std::vector<int> v1(n), v2;

	for (auto &x: v1) std::cin >> x;

	int sum = 0;

	for (int i = 0; i < (int) v1.size() - 1; i ++) {
		v2.push_back(std::abs(v1[i] - v1[i + 1]));
		sum += v2.back();
	}

	std::sort(v2.begin(), v2.end(), std::greater<int>());

	for (int i = 0; i < k - 1; i ++) {
		sum -= v2[i];

		// std::cout << v2[i] << " ";
	}

	std::cout << sum << "\n";
}

int main() {
	int _;

	std::cin >> _;	

	while (_ --) { solve(); }
}