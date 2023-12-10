#include <bits/stdc++.h>
#define FOR(i, j, k) for(int i = j; i <= k; i ++)
using i64 = long long;

int main() {
	int n, m, x;

	std::cin >> n >> m >> x;

	std::vector<int> a(n), b(m);

	int ans = 0;

	for(auto &x: a) std::cin >> x;

	std::reverse(a.begin(), a.end());

	for(auto &x: b) std::cin >> x;

	for(int i = 0, j = 0; i < n; i ++) {
		bool been = false;

		while(j < m && a[i] + b[j] < x) {
			j ++;	
		}

		if(a[i] + b[j] == x) {
			return std::cout << n - i - 1 << " " << j, 0;
		} 
	}
}