#include <bits/stdc++.h>

using i64 = long long;

const int N = 1e5 + 10;

int a[N], s[N];

int main() {
	int n;

	std::cin >> n;

	for(int i = 1; i <= n; i ++) {
	    std::cin >> a[i];
	}

	int ans = 0;

	for(int i = 1, j = 1; j <= n; j ++) {
		s[a[j]] ++;

		while(s[a[j]] > 1) {
			s[a[i ++]] --;	
		}

		ans = std::max(ans, j - i + 1);
	}

	std::cout << ans;
}