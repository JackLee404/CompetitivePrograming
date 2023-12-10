#include <iostream>
#include <unordered_map>
using i64 = long long;

std::unordered_map<int, int> hash;

void init() {
	hash[1] = 1;

	for (i64 i = 2; i <= 1e5; i ++) {
		if (hash[i]) continue;
		for (i64 j = i; j <= 1e5; j *= i) {
			hash[j] = i;
		}
	}
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

		puts(hash[a] == hash[c]?"YES":"NO");
	}
}