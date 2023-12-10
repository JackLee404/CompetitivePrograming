#include <bits/stdc++.h>

using i64 = long long;

std::map<int, int> mp;

int count(int x) {
	for (int i = 2; i <= x / i; i ++) {
		int cnt = 0;
		while (x % i == 0) {
			x /= i;
			cnt ++;
		}
		if (cnt) {
			mp[i] += cnt;
		}
	}
	if (x > 1) mp[x] ++;
}

int main() {
	i64 sum = 1;
	for (int i = 2; i <= 100; i ++) {
		count(i);
	}

	for (int i = 2; i <= 100; i ++) {		
		if (mp[i]) {
			sum *= (1 + mp[i]);
		}
	}

	std::cout << sum << "\n";
}