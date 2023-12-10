#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e3 + 10;

int f[N], s[N], a[N];

int main() {
	int n;
	std::cin >> n;

	int ans = 0;

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];

		s[i] = a[i];

		for(int j = 1; j < i; j ++) {
			if(a[j] < a[i]) {
				s[i] = std::max(s[j] + a[i], s[i]);
			}
		}

		ans = std::max(s[i], ans);
	}

	std::cout << ans;
}