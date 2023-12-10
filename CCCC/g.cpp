#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e6 + 10;

int n0, n1, n;

int st[N];

int main() {
	std::cin >> n0 >> n1 >> n;
	
	std::vector<int> v1;
	
	for (int i = 2; i <= n0 / i; i ++) {
		if (n0 % i == 0) {
			v1.push_back(i);
			if (n0 / i != i) {
				v1.push_back(n0 / i);
			}
		}
	}
	
	for (int i = 2; i <= n1 / i; i ++) {
		if (n1 % i == 0) {
			st[i] = true;
			if (n1 / i != i) {
				st[n1 / i] = true;
			}
		}
	}
	
	int mx1 = -1e8, mx2 = 1e8;
	int t1 = -1, t2 = -1;
	
	for (auto x: v1) {
		if (n - x <= 1) continue;
		
		if (st[n - x]) {
			int p1 = n0 / x, p2 = n1 / (n - x);
			
			if (std::abs(p2 - p1) < std::abs(mx2 - mx1)) {
				mx1 = p1, mx2 = p2;
				t1 = x, t2 = n - x;
			}
		}
	}
	
	if (t1 == -1) {
		puts("No Solution");
		return 0;
	}
	
	std::cout << t1 << " " << t2;
}