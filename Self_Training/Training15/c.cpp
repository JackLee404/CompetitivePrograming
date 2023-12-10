#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e2 + 10;

int a[N];

int main() {
	int n;

	std::cin >> n;

	std::vector<int> a(n);

	for(auto &t: a) {
		std::cin >> t;
	}

	std::cout << *max_element(a.begin(), a.end());
}