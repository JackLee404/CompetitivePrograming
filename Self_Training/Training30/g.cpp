#include <bits/stdc++.h>

using i64 = long long;

const int N = 100, M = 1e4 + 10;

i64 n, cnt, k, a[N], sum[N];

void out(std::vector<i64> &res) {
	for (int i = 0; i < (int) res.size(); i ++) {
		std::cout << res[i] << " \n"[i == (int) res.size() - 1];
	}
}

int main() {
	std::cin >> n >> k;

	for (int i = 1; i <= n; i ++) std::cin >> a[i], sum[i] = a[i] + sum[i - 1];

	std::vector<i64> v1;

	for (int len = 1; len <= n; len ++) {
		for (int l = 1; l + len - 1 <= n; l ++) {
			int r = l + len - 1;
			
			v1.push_back(sum[r] - sum[l] + a[l]);

			// std::cout << l << " " << r << "\n";
		}
	}

	std::sort(v1.begin(), v1.end());

	

	// int len = std::unique(v1.begin(), v1.end()) - v1.begin();

	out(v1);

	// i64 tag = 1, k2 = k;

	// std::vector<i64> res;

	// for (int i = 0; i < len; i ++) {
	// 	if (!k2) break;

	// 	// std::cout << v1[i] << " \n"[i == len - 1];

	// 	if (v1[i] == tag) tag ++;
	// 	else {
	// 		while (k2 && tag < a[i]) {
	// 			res.push_back(tag ++);
	// 			k2 --;
	// 		}
	// 	}
	// }


	// for (int i = 1; i <= k2; i ++) {
	// 	res.push_back(v1[len - 1] + i);
	// }
	

	// for (int i = 0; i < res.size(); i ++) {
	// 	std::cout << res[i] << " \n"[i == (int) res.size() - 1];
	// }
}