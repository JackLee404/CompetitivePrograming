#include <iostream>
#include <unordered_map>
using i64 = long long;

std::unordered_map<int, int> hash, hash2;

void init() {
	hash[1] = 1;
	hash2[1] = 0;

	for (i64 i = 2; i <= 1e5; i ++) {
		if (hash[i]) continue;
		for (i64 j = i, cnt = 1; j <= 1e5; j *= i, cnt ++) {
			hash[j] = i;
			hash2[j] = cnt;
		}
	}
}

int gcd(int a, int b) {
	return b?gcd(b, a % b):a;
}

int main() {
	init();

	int _;

	std::cin >> _;

	while (_ --) {
		int a, b, c, d;

		std::cin >> a >> b >> c >> d;

		if (!hash[a] || !hash[c]) {
			puts("NO");
			continue;
		}

		puts((hash[a] == hash[c] && hash2[a] * b == hash2[c] * d)?"YES":"NO");
	}
}