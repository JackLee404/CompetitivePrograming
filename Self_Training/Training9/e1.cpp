#include <bits/stdc++.h>

using i64 = long long;

/*
1 2 3
*/

int main() {
	int n;
	std::cin >> n;

	std::vector<int> a(n + 1);
	std::vector<int> prefix(n + 1);

	for(int i = 1; i <= n; i ++) {
		std::cin >> a[i];
		prefix[i] = prefix[i - 1] + a[i];
	}

	if(prefix[n] % 3 || n < 3) {
		std::cout << 0;
		return 0;
	}

	int ans = 0, cnt = 0;

	for(int i = 1, j = 2; j < n; i ++, j ++) {
		if(prefix[i] == prefix[n] / 3) cnt ++;
		if(prefix[n] - prefix[j] == prefix[n] / 3) ans += cnt;
	}

	std::cout << ans;
}