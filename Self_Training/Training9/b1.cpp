#include <bits/stdc++.h>

using i64 = long long;

const int N = 200;

int f[N], f1[N], a[N];

int main() {
	int n, ans = 0;
	
	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		f[i] = 1;

		for(int j = 1; j < i; j ++) {
			if(a[j] < a[i]) {
				f[i] = std::max(f[i], f[j] + 1);
			} 
		}
	}

	for(int i = n; i >= 1; i ++) {

		f1[i] = 1;

		for(int j = n; j > i; j --) {
			if(a[j] < a[i]) {
				f1[i] = std::max(f1[i], f1[j] + 1);
			}
		}

		ans = std::max(ans, f1[i] + f[i] - 1);
	}

	std::cout << n - ans;
}
