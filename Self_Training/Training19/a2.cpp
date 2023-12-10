#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>

using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(0);
	std::cout.tie(0);

	int w, n;

	std::cin >> w >> n;


	std::vector<int> a(n);

	for (auto &x: a) std::cin >> x;

	std::sort(a.begin(), a.end());

	int ans = 0;
	
	for (int i = 0, j = n - 1; i <= j;) {
		if (i == j) {
			ans ++;
			break;
		}
		if (a[i] + a[j] > w) {	
			ans ++;
			j --;
		} else {
			ans ++;
			i ++;
			j --;			
		}
	}

	std::cout << ans;
}