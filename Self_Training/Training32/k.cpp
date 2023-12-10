#include <vector>
#include <iostream>
#include <algorithm>

using i64 = long long;

int main() {
	int n;

	std::cin >> n;

	std::vector<int> v(n);

	for (auto &x: v) std::cin >> x;

	std::sort(v.begin(), v.end());

	std::vector<int> v1, v2, v3;

	for (int i = 0; i <= n / 2; i ++) v1.push_back(v[i]);

	for (int i = n / 2 + 1; i < n; i ++) v2.push_back(v[i]);

	int st1 = 0, st2 = 0;

	int k;

	for (int i = 0; i < n; i ++) {
		if (i % 2 == 0) k = v1[st1 ++];
		else k = v2[st2 ++];

		v3.push_back(k);
	}

	// for (int i = 0; i < n; i ++) {
	// 	std::cout << v3[i] << " ";
	// }

	for (int i = 1; i < n; i += 2) {
		if (!(v3[i] > v3[i - 1] && v3[i] > v3[i + 1])) {
			return puts("No"), 0;
		};
	}

	puts("Yes");
}