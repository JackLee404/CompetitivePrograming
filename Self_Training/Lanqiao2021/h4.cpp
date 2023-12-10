#include <iostream>

using i64 = long long;

i64 n;

const int N = 1e9, M = 33, mod = 1e6;

i64 C(int a, int b) {
	i64 res = 1;

	for(i64 i = a, j = 1; j <= b; j ++, i --) {
		res = res * i / j;

		if(res > n) {
			return res;
		}
	}	

	return res;
}

int main() {
	


	std::cin >> n;

	// 计算列数上界
	// int k = 16;

	// std::cout << C(5, 2) << "\n";

	// for(int i = 1; ; i ++) {	
	// 	if(C(2 * i, i) >= 1e9) {
	// 		std::cout << i;
	// 		break;
	// 	}
	// }

	for(int i = 17; i >= 0; i --) {

		int l = 2 * i, r = std::max((i64)2 * i, n);

		while(l < r) {
			int mid = l + r >> 1;
			if(C(mid, i) >= n) r = mid;
			else l = mid + 1;
		}

		// std::cout << C(l, i) << "\n";

		if(C(l, i) == n) {
			i64 ans = ((i64)(1 + l) * l / 2) + (i + 1);

			// std::cout << l << " " << i << "\n";
			std::cout << ans;
			break;
		}
	}
}