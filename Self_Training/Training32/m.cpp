#include <bits/stdc++.h>
#include <cmath>

using i64 = long long;

int n;

int g(int x) {
	return x ^ (x >> 1);
}

inline void out(std::vector<int> &v) {
	for (int i = 0; i < (int) v.size(); i ++) {
		std::cout << v[i] << " \n"[i == (int) v.size() - 1];
	}
}

int main() {
	std::cin >> n;

	std::vector<int> v;

	int ct = 0;

	for (int i = 0; i < pow(2, n * 2); i ++) {
		v.push_back(g(i));

		if ((i + 1) % (int) pow(2, n) == 0) {
			if (ct % 2 != 0) std::reverse(v.begin(), v.end());

			out(v);

			ct ++, v.clear();
		}
	}
}